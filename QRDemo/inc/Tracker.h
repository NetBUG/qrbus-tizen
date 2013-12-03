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

#ifndef _TRACKER_H_
#define _TRACKER_H_

#include <FBase.h>
#include <FMedia.h>
#include <FUix.h>
#include <FSystem.h>
#include "QRMessagePort.h"


#include "GLtools.h"
#include "Renderer.h"


class Tracker
    : public Tizen::Media::ICameraEventListener
{
public:
    Tracker(void);
    virtual ~Tracker(void);

    void Init(Tizen::Ui::Controls::Form*);
    void DoRendering(bool);
    void Terminate(void);

    // Called when camera auto focus occurred
    void OnCameraAutoFocused(bool completeCondition);

    // Called when camera preview occurred
    void OnCameraPreviewed(Tizen::Base::ByteBuffer& previewedData, result r);

    // Called when camera captured image
    void OnCameraCaptured(Tizen::Base::ByteBuffer& capturedData, result r);

    // Called when camera  error occurred
    void OnCameraErrorOccurred(Tizen::Media::CameraErrorReason r);

    void ConvertNV12ToYCbCr(byte *src, byte *dst, int width, int height);

    static const int DESIRED_CAMERA_WIDTH  = 640;
    static const int DESIRED_CAMERA_HEIGHT = 480;

private:
    void InitRecognizer(void);
    void Focus(bool);

private:
    Tizen::Uix::Vision::QrCodeRecognizer*      __pQrRecognizer;
    Renderer*                                  __pRenderer;
    Tizen::Graphics::Rectangle*                __pRoi;
    Tizen::Ui::Controls::Label*                __pLabel;
    Tizen::Base::String                        __qrText;
    Tizen::Ui::Controls::Form*                 __pForm;
	QRMessagePort* __pMessagePort;

    bool __doRender;
    bool __terminating;
};

#endif
