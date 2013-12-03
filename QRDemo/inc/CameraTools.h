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

#ifndef CAMERA_TOOLS_H_
#define CAMERA_TOOLS_H_

#include <FMedia.h>
#include <FGraphics.h>

class CameraTools
{

private:
    CameraTools();
    CameraTools(const CameraTools&);
    CameraTools& operator=(const CameraTools&);
    ~CameraTools();

public:

    //Does all necessary initialization
    static bool InitCamera(Tizen::Media::ICameraEventListener &listener,
                            const unsigned int width, const unsigned int height);

    static void StopCamera(void);

    static bool StartCamera(void);

    static Tizen::Media::Camera* GetCamera(void);

    static int GetWidth(void);
    static int GetHeight(void);
    static Tizen::Graphics::PixelFormat GetFormat(void);

private:

    static Tizen::Media::Camera*               __pCamera;
    static Tizen::Graphics::Dimension          __chosenResolution;
    static Tizen::Media::ICameraEventListener* __pListener;
    static int __width;
    static int __height;
    static Tizen::Graphics::PixelFormat __format;
};

#endif //CAMERA_TOOLS_H_
