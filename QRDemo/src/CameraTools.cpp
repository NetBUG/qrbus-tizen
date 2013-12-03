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

#include "CameraTools.h"
#include <FBaseSysLog.h>

using namespace Tizen::Base;
using namespace Tizen::Media;
using namespace Tizen::Graphics;


Camera*  CameraTools::__pCamera(null);
Tizen::Graphics::Dimension CameraTools::__chosenResolution;
int CameraTools::__width;
int CameraTools::__height;
Tizen::Media::ICameraEventListener*  CameraTools::__pListener(null);
Tizen::Graphics::PixelFormat CameraTools::__format;

const char* pTag = "CameraTools";

bool
CameraTools::InitCamera(ICameraEventListener &listener,
                              const unsigned int width, const unsigned int height)
{

    __chosenResolution = Tizen::Graphics::Dimension(width, height);
    __pListener         = &listener;

    if (__pCamera)
    {
    	StopCamera();
    }

    std::unique_ptr<Camera> pCamera (new (std::nothrow) Camera());
	SysTryReturn(NID_APP, pCamera != null, false, E_OUT_OF_MEMORY, "[%s] Memory allocation failed.", GetErrorMessage(E_OUT_OF_MEMORY));
    __pCamera = pCamera.release();

    if (null == __pCamera)
    {
        return false;
    }

    if (IsFailed(__pCamera->Construct(*__pListener, CAMERA_PRIMARY)))
    {
    	AppSecureLogExceptionTag(pTag, "Construct failed with %s", GetErrorMessage(GetLastResult()));
    	delete __pCamera;
    	__pCamera = null;
        return false;
    }

    if (IsFailed(__pCamera->PowerOn()))
    {
    	AppSecureLogExceptionTag(pTag, "PowerOn failed with %s", GetErrorMessage(GetLastResult()));
        return false;
    }

	__format = PIXEL_FORMAT_MIN;

   Tizen::Base::Collection::IListT<Tizen::Graphics::PixelFormat>* PreviewList = __pCamera->GetSupportedPreviewFormatListN();

	for (int i = 0; i < PreviewList->GetCount(); i++)
	{
		Tizen::Graphics::PixelFormat format;

		PreviewList->GetAt(i,format);
		if(format == PIXEL_FORMAT_YCbCr420_PLANAR)
		{
			__format = PIXEL_FORMAT_YCbCr420_PLANAR;
			break;
		}else if (format == PIXEL_FORMAT_NV12)
		{
			__format = PIXEL_FORMAT_NV12;
		}
	}
    
	
    if (IsFailed(__pCamera->SetPreviewFormat(__format)))
    {
    	AppSecureLogExceptionTag(pTag, "SetPreviewFormat failed with %s", GetErrorMessage(GetLastResult()));
        return false;
    }

    if (IsFailed(__pCamera->SetPreviewFrameRate(30)))
    {
    	AppSecureLogExceptionTag(pTag, "SetPreviewFrameRate failed with %s", GetErrorMessage(GetLastResult()));
        return false;
    }

    Tizen::Base::Collection::IList* _pList = __pCamera->GetSupportedPreviewResolutionListN();

    if (_pList)
    {
        int _count = _pList->GetCount();
        if (_count)
        {
            Tizen::Base::Collection::IEnumerator* _pEnum = _pList->GetEnumeratorN();
            if (_pEnum)
            {
                result _res = E_SUCCESS;
                int _area; //area of camera preview image

                while (E_SUCCESS == _res)
                {
                    _res = _pEnum->MoveNext();
                    switch (_res)
                    {
                    case E_SUCCESS:
                    {
                        Tizen::Graphics::Dimension* _pSupportedDim = (Tizen::Graphics::Dimension*) _pEnum->GetCurrent();
                        if (_pSupportedDim)
                        {
                            if (_pSupportedDim->width <= width && _pSupportedDim->height <= height)
                            {
                                int _supportedArea = _pSupportedDim->width * _pSupportedDim->height;
                                if (_supportedArea > _area)
                                {
                                    __chosenResolution = *_pSupportedDim;
                                    _area = _supportedArea;
                                }
                            }
                        }
                        break;
                    }
                    case E_OUT_OF_RANGE:
                        break;
                    case E_INVALID_OPERATION:
                    default:
                        break;
                    }
                }
                delete _pEnum;
            }

        }
        delete _pList;
    }

    if (IsFailed(__pCamera->SetPreviewResolution(__chosenResolution)))
    {
    	AppSecureLogExceptionTag(pTag, "SetPreviewResolution failed with %s", GetErrorMessage(GetLastResult()));
        return false;
    }

	if (IsFailed(__pCamera->SetFocusMode(Tizen::Media::CAMERA_FOCUS_MODE_NORMAL)))
	{
		AppSecureLogExceptionTag(pTag, "SetFocusMode CAMERA_FOCUS_MODE_NORMAL failed with %s", GetErrorMessage(GetLastResult()));
	}

    __width  = __pCamera->GetPreviewResolution().width;
    __height = __pCamera->GetPreviewResolution().height;

    return __pCamera->GetState() != CAMERA_STATE_ERROR;
}

void
CameraTools::StopCamera(void)
{
	if (__pCamera)
	{
		if (__pCamera->IsPoweredOn())
		{
			if (CAMERA_STATE_PREVIEW == __pCamera->GetState() || CAMERA_STATE_AUTO_FOCUSING == __pCamera->GetState())
			{
				if (IsFailed(__pCamera->StopPreview()))
				{
					AppSecureLogExceptionTag(pTag, "StopPreview failed with %s", GetErrorMessage(GetLastResult()));
				}
			}
			else
			{
				AppSecureLogExceptionTag(pTag, "StopPreview camera state %i", __pCamera->GetState());
			}

			if (IsFailed(__pCamera->PowerOff()))
			{
				AppSecureLogExceptionTag(pTag, "PowerOff failed with %s", GetErrorMessage(GetLastResult()));
			}
		}

		delete __pCamera;
		__pCamera = null;
	}
    return;
}

bool
CameraTools::StartCamera(void)
{
	if (__pCamera && __pCamera->IsPoweredOn())
	{
		AppSecureLogExceptionTag(pTag, "Restart camera state %i", __pCamera->GetState());

		switch(__pCamera->GetState())
		{
		case CAMERA_STATE_INITIALIZED:
			//no break;
		case CAMERA_STATE_CAPTURED:
			if (IsFailed(__pCamera->StartPreview(null, true)))
			{
				AppSecureLogExceptionTag(pTag, "StartPreview failed with %s", GetErrorMessage(GetLastResult()));
				StopCamera();
				return false;
			}
			//no break
		case CAMERA_STATE_PREVIEW:
			//no break
		case CAMERA_STATE_AUTO_FOCUSING:
			return true;
		case CAMERA_STATE_ERROR:
			AppSecureLogExceptionTag(pTag, "Camera is in error state");
			StopCamera();
			return StartCamera();
		default:
			AppSecureLogExceptionTag(pTag, "Camera is in state %i", __pCamera->GetState());
			return false;
		}
	}
	else
	{
		if (__pListener && InitCamera(*__pListener, __chosenResolution.width, __chosenResolution.height))
		{
			return StartCamera();
		}

		AppSecureLogExceptionTag(pTag, "Camera was not initialized");

		return false;
	}
}

Camera*
CameraTools::GetCamera(void)
{
    return __pCamera;
}

int
CameraTools::GetWidth(void)
{
    return __width;
}

int
CameraTools::GetHeight(void)
{
    return __height;
}

Tizen::Graphics::PixelFormat
CameraTools::GetFormat(void)
{
    return __format;
}
