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

#ifndef _GLTOOLS_H_
#define _GLTOOLS_H_


#include <FGraphics.h>
#include <FUi.h>
#include <FGraphicsOpengl2.h>

class GLtools
{

private:
    GLtools();
    GLtools(const GLtools&);
    GLtools& operator=(const GLtools&);
    ~GLtools();


public:

    static bool                     initGL(Tizen::Ui::Container *const);
    static void                     destroyGL();
    static bool                     startDrawing();
    static void                     finishDrawing();
    static Tizen::Ui::Container*      getCurrentGLContainer();
    static int                      getWidth();
    static int                      getHeight();

private:
    static bool initEGL();


private:
    static Tizen::Graphics::Opengl::EGLDisplay    eglDisplay;
    static Tizen::Graphics::Opengl::EGLSurface    eglSurface;
    static Tizen::Graphics::Opengl::EGLConfig     eglConfig;
    static Tizen::Graphics::Opengl::EGLContext    eglContext;
    static Tizen::Ui::Container*                  pContainer;
    static int x, y, screenWidth, screenHeight;

};

#endif // __GLTOOLS_H__
