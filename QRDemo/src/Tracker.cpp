//
// Tizen C++ SDK
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "AppResourceId.h"
#include "Tracker.h"
#include "CameraTools.h"

#include <FApp.h>
#include <FIo.h>

using namespace Tizen::Graphics;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

static const wchar_t* LOCAL_MESSAGE_PORT_NAME = L"QR_PORT";

Tracker::Tracker()
    : __pQrRecognizer(0)
    , __pRenderer(0)
    , __pRoi(0)
    , __pLabel(0)
    , __pForm(0)
    , __doRender(true)
    , __terminating(false)
{
}

Tracker::~Tracker()
{
    if (__pQrRecognizer)
    {
        delete __pQrRecognizer;
    }
    if (__pRenderer)
    {
        delete __pRenderer;
    }
    if (__pRoi)
    {
        delete __pRoi;
    }

}

void
Tracker::Init(Tizen::Ui::Controls::Form* form)
{
    __pRenderer = new Renderer();
    __pRenderer->SetCameraAngle(0.4636476*2);
    __pRenderer->Init(CameraTools::GetWidth(), CameraTools::GetHeight());
    __pRoi = new Tizen::Graphics::Rectangle;
    __pLabel = static_cast<Tizen::Ui::Controls::Label *>(form->GetControl(IDC_INFO_LABEL));
    __pForm = form;

	__pMessagePort = new (std::nothrow) QRMessagePort();
	int r = __pMessagePort->Construct(LOCAL_MESSAGE_PORT_NAME);

	InitRecognizer();
}

void
Tracker::InitRecognizer(void)
{
    __pQrRecognizer = new Tizen::Uix::Vision::QrCodeRecognizer();
    __pQrRecognizer->Construct();
    __pQrRecognizer->SetImageSize(CameraTools::GetWidth(), CameraTools::GetHeight());
}

// Called when camera auto focus occurred
void
Tracker::OnCameraAutoFocused(bool completeCondition)
{
}

// Called when camera preview occurred
void
Tracker::OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r)
{
    if (__doRender && !__terminating)
    {
        bool was_object = false;

        Tizen::Base::ByteBuffer* pBuffer = new (std::nothrow) ByteBuffer();
		TryReturn(pBuffer != null, , "Failed to create ByteBuffer");
		/* check the preview format*/
		if (CameraTools::GetFormat() == PIXEL_FORMAT_NV12)
		{
			byte *pSrcArray = null;
			byte *pDstArray = null;
			pBuffer->Construct((CameraTools::GetHeight()*CameraTools::GetWidth())*1.5);

			pSrcArray = previewedData.GetPointer();
			pDstArray = pBuffer->GetPointer();

			ConvertNV12ToYCbCr(pSrcArray,pDstArray,CameraTools::GetHeight(),CameraTools::GetWidth());
		}/*check the preview format*/
		else
		{
			pBuffer->Construct(previewedData);
		}

        __pQrRecognizer->ProcessImage(*pBuffer);


        if (GLtools::startDrawing())
        {
            __pRenderer->SetTextureData(CameraTools::GetWidth(), CameraTools::GetHeight(), (unsigned char*) pBuffer->GetPointer());
            static float zeroBuffer[4][4] = {{ 0, 0, 0, 0}};
            static Tizen::Graphics::FloatMatrix4 zeroMatrix(zeroBuffer);
            __pRenderer->SetModelViewMatrix(0, &zeroMatrix);
            __pLabel->SetText("");

            for (int i = 0; i < __pQrRecognizer->GetRecognizedObjectCount(); i++)
            {
                const Tizen::Uix::Vision::QrCodeObject *o = __pQrRecognizer->GetRecognizedObject(i);
                if (o->GetText().IsEmpty())
				{
				   // Set the previous message
				   __pLabel->SetText(__qrText);
				}
				else
				{
				   // Change the message
				   __qrText = o->GetText();
				   __pLabel->SetText(o->GetText());
					result r = E_SUCCESS;
					// Initialize ServerMessagePort

				    if (__pMessagePort != null)
					{
						HashMap *pMap =	new HashMap(SingleObjectDeleter);
						pMap->Construct();
						//pMap->Add(new String(L"server"), new String(__qrText));
						pMap->Add(new String(L"server"), new String(L"play"));

						__pMessagePort->SendMessage(pMap);

						delete pMap;
						Tizen::App::Application::GetInstance()->Terminate();
					}
					else
					{
				    	MessageBox msgBox;
				    	int result = 0;
						msgBox.Construct("Warning", "No MessagePort found :(", MSGBOX_STYLE_NONE, 3000);
						msgBox.ShowAndWait(result);
					}
				}
                __pRenderer->SetModelViewMatrix(0, o->GetTransformMatrix());
                was_object = true;
            }
            this->Focus(was_object);
            __pRenderer->Draw();
            GLtools::finishDrawing();
        }

        __pForm->Draw();

        if(pBuffer)
        	delete pBuffer;
    }
    else if (__terminating)
    {
        __terminating = false;
        __doRender = false;
        Tizen::App::Application::GetInstance()->Terminate();
        return;
    }
}

// Called when camera captured image
void
Tracker::OnCameraCaptured(Tizen::Base::ByteBuffer& capturedData, result r)
{
}

// Called when camera  error occurred
void
Tracker::OnCameraErrorOccurred(Tizen::Media::CameraErrorReason r)
{
	AppSecureLogExceptionTag("CameraTools", "Camera state %i, Camera error reason %i", CameraTools::GetCamera()->GetState(), r);
}

void
Tracker::DoRendering(bool render)
{
    __doRender = render;
}

void
Tracker::Terminate(void)
{
    __terminating = true;
}

void
Tracker::Focus(bool objectVisible)
{
    static unsigned int frames = 0;
    static Tizen::Graphics::Point  pt(0, 0);
    Tizen::Base::Collection::ArrayList list;

    frames++;

    if (frames >= 60)
    {
    	AppSecureLogTag("Tracker", "%s %i %i %i %i", GetErrorMessage(__pQrRecognizer->GetFocusRoi(*__pRoi)),
    			__pRoi->x,
    			__pRoi->y,
    			__pRoi->x + __pRoi->width,
    			__pRoi->y + __pRoi->height);
        if ( objectVisible && E_SUCCESS == __pQrRecognizer->GetFocusRoi(*__pRoi) )
        {
            float x = 0, y = 0;
            x = __pRoi->x + __pRoi->width / 2;
            y = __pRoi->y + __pRoi->height / 2;
            pt.SetPosition((x + 0.5) * CameraTools::GetWidth(), (y + 0.5) * CameraTools::GetHeight());
        }
        else
        {
            pt.SetPosition(CameraTools::GetWidth() >> 1, CameraTools::GetHeight() >> 1);
        }

        static bool already_focused = false;
        if (!(objectVisible && already_focused))
        {
            list.RemoveAll(false);
            list.Add(pt);
            if (IsFailed(CameraTools::GetCamera()->SetAutoFocusPoint(list)))
            {
            	AppSecureLogExceptionTag("CameraTools", "Tracker SetAutoFocusPoint failed %s", GetErrorMessage(GetLastResult()));
            }
            if (IsFailed(CameraTools::GetCamera()->SetAutoFocus(false)))
            {
            	AppSecureLogExceptionTag("CameraTools", "Tracker SetAutoFocus failed %s", GetErrorMessage(GetLastResult()));
            }

            already_focused = objectVisible;
        }
        frames = 0;
    }
}

void
Tracker::ConvertNV12ToYCbCr(byte *src, byte *dst, int width, int height)
{
	byte *pSrcStart = src;
	byte *pDstStart = dst;
	byte *pDstUStart = dst + width*height;
	byte *pDstVStart = pDstUStart + width*height/4;

	//Copy Y Components
	memcpy(pDstStart, pSrcStart, (width*height));
	pSrcStart += width*height;

	//Copy UV Components
	for (int i = 0; i < (width*height)/4; i++)
	{
		*pDstUStart++ = *pSrcStart++;
		*pDstVStart++ = *pSrcStart++;
	}

	return;
}
