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

#include "GLtools.h"

using namespace Tizen::Graphics::Opengl;

EGLDisplay               GLtools::eglDisplay(EGL_DEFAULT_DISPLAY);
EGLSurface               GLtools::eglSurface(EGL_NO_SURFACE);
EGLConfig                GLtools::eglConfig(null);
EGLContext               GLtools::eglContext(EGL_NO_DISPLAY);
Tizen::Ui::Container*    GLtools::pContainer(null);
int                      GLtools::x(0);
int                      GLtools::y(0);
int                      GLtools::screenWidth(0);
int                      GLtools::screenHeight(0);


Tizen::Ui::Container*
GLtools::getCurrentGLContainer()
{
    return pContainer;
}

bool
GLtools::initEGL()
{
    EGLint numConfigs = 1;
    EGLint eglConfigList[] = {
            EGL_RED_SIZE,	5,
            EGL_GREEN_SIZE,	6,
            EGL_BLUE_SIZE,	5,
            EGL_ALPHA_SIZE,	0,
            EGL_DEPTH_SIZE, 8,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
            EGL_NONE
    };
    EGLint eglContextList[] = {
            EGL_CONTEXT_CLIENT_VERSION, 2,
            EGL_NONE
    };

    eglBindAPI(EGL_OPENGL_ES_API);

    if (eglDisplay)
    {
        return false;
    }

    eglDisplay = eglGetDisplay((EGLNativeDisplayType) EGL_DEFAULT_DISPLAY);
    if (EGL_NO_DISPLAY == eglDisplay)
    {
        return false;
    }

    if (EGL_FALSE == eglInitialize(eglDisplay, null, null) || EGL_SUCCESS != eglGetError())
    {
        return false;
    }

    if (EGL_FALSE == eglChooseConfig(eglDisplay, eglConfigList, &eglConfig, 1, &numConfigs) || EGL_SUCCESS != eglGetError())
    {
        return false;
    }

    if (!numConfigs)
    {
        return false;
    }

    eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, (EGLNativeWindowType) pContainer, null);

    if (EGL_NO_SURFACE == eglSurface || EGL_SUCCESS != eglGetError())
    {
        return false;
    }

    eglContext = eglCreateContext(eglDisplay, eglConfig, EGL_NO_CONTEXT, eglContextList);
    if (EGL_NO_CONTEXT == eglContext || EGL_SUCCESS != eglGetError())
    {
        return false;
    }

    if (EGL_FALSE == eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext) || EGL_SUCCESS != eglGetError())
    {
        return false;
    }

    return true;
}

bool
GLtools::initGL(Tizen::Ui::Container *const container)
{
    if (pContainer == container)
    {
        return true;
    }

    if (pContainer)
    {
        destroyGL();
    }
    pContainer = container;

    if (!initEGL())
    {
        destroyGL();
        pContainer        = null;
        x            = 0;
        y            = 0;
        screenWidth  = 0;
        screenHeight = 0;
        return false;
    }

    pContainer->GetBounds(x, y, screenWidth, screenHeight);

    return true;
}

void
GLtools::destroyGL()
{
    if (eglDisplay)
    {
        eglMakeCurrent(eglDisplay, null, null, null);

        if (eglContext)
        {
            eglDestroyContext(eglDisplay, eglContext);
            eglContext = EGL_NO_CONTEXT;
        }

        if (eglSurface)
        {
            //eglDestroySurface(eglDisplay, eglSurface);
            eglSurface = EGL_NO_SURFACE;
        }

        //eglTerminate(eglDisplay);
        eglDisplay = EGL_NO_DISPLAY;
    }

    pContainer = null;
    return;
}

bool
GLtools::startDrawing()
{
    if (!pContainer->IsEnabled()) return false;

    if (GL_FALSE == eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext) || EGL_SUCCESS != eglGetError())
    {
    	return false;
    }

    glViewport(x, y, screenWidth, screenHeight);

    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    return true;
}


void
GLtools::finishDrawing(void)
{
    eglSwapBuffers(eglDisplay, eglSurface);
}

int
GLtools::getWidth(void)
{
    return (screenWidth);
}

int
GLtools::getHeight(void)
{
    return (screenHeight);
}
