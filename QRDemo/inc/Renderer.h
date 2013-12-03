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

#ifndef RENDERER_H_
#define RENDERER_H_

#include <FGraphics.h>
#include <FUi.h>
#include <FGraphicsOpengl2.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace Tizen::Graphics::Opengl;

#define CUBE_COUNT    16

class Renderer
{
public:
    Renderer();
    ~Renderer();

    void Init(int width, int height);
    void SetTextureData( int width, int height, void* data );
    void SetModelViewMatrix( int i, const Tizen::Graphics::FloatMatrix4* );
    void SetCameraAngle( float angle );
    void Draw();
    void Update(float t);

private:

    /// Load a shader, check for compile errors, print error messages to output log
    GLuint loadShader(GLenum type, const char *shaderSrc);

    /// Load a vertex and fragment shader, create a program object, link program. Errors output to log.
    GLuint loadProgram(const char *vertShaderSrc, const char *fragShaderSrc);

    GLuint createSimpleTexture2D(GLenum type, int width, int height);

    /// Simulates desktop's glRotatef. The matrix is returned in column-major order.
    void rotateMatrix(double angle, double x, double y, double z, float *R);

    /// Simulates gluPerspectiveMatrix
    void perspectiveMatrix(double fovy, double aspect, double znear, double zfar, float *P);

    /// Multiplies A by B and writes out to C. All matrices are 4x4 and column major. In-place multiplication is supported.
    void multiplyMatrix(const float *A, const float *B, float *C);

    GLuint  __programObject;

    // Attribute locations
    GLint   __positionLoc;
    GLint   __texCoordLoc;
    GLint   __colorLoc;
    GLint   __mvpPLoc;

    // Sampler location
    GLint   __samplerLoc;
    GLint   __samplerColorLoc;

    // Texture handle
    GLuint  __textureId;
    GLuint  __textureColorId;

    float   __modelView[CUBE_COUNT][16];
    float   __perspectiveMatrix[16];
    float   __mvp2[16];
    float   __cameraAngle;

};

#endif // RENDERER_H_
