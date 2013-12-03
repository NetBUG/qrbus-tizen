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

#include "Renderer.h"

#include "CameraTools.h"
#include "GLtools.h"
#include "Cubes.h"

using namespace Tizen::Graphics::Opengl;

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void
Renderer::SetTextureData(int width, int height, void* data)
{
    glBindTexture   (GL_TEXTURE_2D, __textureColorId);
    glTexSubImage2D (GL_TEXTURE_2D, 0, 0, 0, width >> 1, height >> 1, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, ((unsigned char*) data) + width * height);
    glBindTexture   (GL_TEXTURE_2D, __textureId);
    glTexSubImage2D (GL_TEXTURE_2D, 0, 0, 0, width, height, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
}

void
Renderer::SetModelViewMatrix(int i, const Tizen::Graphics::FloatMatrix4* mat)
{
    if (mat)
        memcpy(__modelView[i], mat->matrix, 16 * sizeof(float));

    float matrix[16] = {0.f};
    multiplyMatrix(leftTransform, __modelView[i], matrix);
    multiplyMatrix(matrix, rightTransform, __modelView[i]);
}

void
Renderer::SetCameraAngle(float angle)
{
    __cameraAngle = angle;
}

void
Renderer::Init(int width, int height)
{
    GLbyte vShaderStr[] =
        "attribute vec4 a_Position;           \n"
        "attribute vec2 a_TexCoord;           \n"
        "attribute vec3 a_Colour;             \n"
        "                                     \n"
        "uniform mat4 u_Mvp;                  \n"
        "                                     \n"
        "varying vec2 v_TexCoord;             \n"
        "varying vec3 v_Colour;               \n"
        "                                     \n"
        "void main()                          \n"
        "{                                    \n"
        "   gl_Position = u_Mvp * a_Position; \n"
        "   v_TexCoord  = a_TexCoord;         \n"
        "   v_Colour    = a_Colour;           \n"
        "}                                    \n";

    GLbyte fShaderStr[] =
        "precision mediump float;                                                                             \n"
        "uniform sampler2D s_Texture;                                                                         \n"
        "uniform sampler2D s_TextureColor;                                                                    \n"
        "varying vec2 v_TexCoord;                                                                             \n"
        "varying vec3 v_Colour;                                                                               \n"
        "                                                                                                     \n"
        "void main()                                                                                          \n"
        "{                                                                                                    \n"
        "    float y = texture2D(s_Texture, v_TexCoord).r + v_Colour.r;                                       \n"
        "    float v = texture2D(s_TextureColor, vec2(v_TexCoord.x, v_TexCoord.y) * 0.5).r + v_Colour.b - 0.5;\n"
        "    float u = texture2D(s_TextureColor, vec2(v_TexCoord.x, v_TexCoord.y + 1.0) * 0.5).a + v_Colour.g - 0.5;\n"
        "    float r = y + 1.772 * u;                                                                         \n"
        "    float g = y - 0.34414 * u - 0.71414 * v;                                                         \n"
        "    float b = y + 1.402 * v;                                                                         \n"
        "    gl_FragColor = vec4(r, g, b, 1.0);                                                               \n"
        "}                                                                                                    \n";

    // Load the shaders and get a linked program object
    __programObject = loadProgram ((char *)vShaderStr, (char *)fShaderStr);

    // Get the attribute locations
    __positionLoc   = glGetAttribLocation (__programObject, "a_Position");
    __texCoordLoc   = glGetAttribLocation (__programObject, "a_TexCoord");
    __colorLoc  = glGetAttribLocation (__programObject, "a_Colour");

    // Get the sampler location
    __samplerLoc = glGetUniformLocation (__programObject, "s_Texture");
    __samplerColorLoc = glGetUniformLocation (__programObject, "s_TextureColor");
    __mvpPLoc    = glGetUniformLocation (__programObject, "u_Mvp");

    // Load the texture
    __textureId = createSimpleTexture2D (GL_LUMINANCE, width, height);
    __textureColorId = createSimpleTexture2D (GL_LUMINANCE_ALPHA, width >> 1, height >> 1);

    __mvp2[0]  = 1; __mvp2[1]  = 0; __mvp2[2]  = 0; __mvp2[3]  = 0;
    __mvp2[4]  = 0; __mvp2[5]  = 1; __mvp2[6]  = 0; __mvp2[7]  = 0;
    __mvp2[8]  = 0; __mvp2[9]  = 0; __mvp2[10] = 1; __mvp2[11] = 0;
    __mvp2[12] = 0; __mvp2[13] = 0; __mvp2[14] = 0; __mvp2[15] = 1;

    for(int i = 0; i < CUBE_COUNT; ++i)
    {
        memset(__modelView[i], 0, 16 * sizeof(float));
    }

    float u[] = {0.f, 0.25f, 0.f};
    float v[] = {0.f, 0.f, 0.25f};
    for(int j = 0; j < 3; ++j)
    {
        for(int i = 0; i < 36; ++i)
        {
            colorList[j][i * 3] = aColours[i * 3];
            colorList[j][i * 3 + 1] = aColours[i * 3 + 1] + u[j];
            colorList[j][i * 3 + 2] = aColours[i * 3 + 2] + v[j];
        }
    }
}

void
Renderer::Draw(void)
{

#ifdef PORTRAIT
    float glScale = (float)GLtools::getHeight() / GLtools::getWidth();
#else
    float glScale = (float)GLtools::getWidth() / GLtools::getHeight();
#endif
    float cScale  = (float)CameraTools::GetWidth() / CameraTools::GetHeight();

    float scaleWidth  = 1.0f;
    float scaleHeight = 1.0f;




    if (cScale < glScale)
    {
        scaleHeight = cScale / glScale;
    }
    else
    {
        scaleWidth = cScale / glScale;
    }


    float widthShift  = (1.f - scaleWidth) / 2.f;
    float heightShift = (1.f - scaleHeight) / 2.f ;


    GLfloat vVertices[] = {
#ifdef PORTRAIT
             1.0f                   ,  1.0f                     , 0.0f,       // Position 3
#else
            -1.0f                   ,  1.0f                     , 0.0f,       // Position 0
#endif
             0.0f                   ,  heightShift              ,                              // TexCoord 0
             0.f                    ,  0.0f                     , 0.0f,       // Color

#ifdef PORTRAIT
            -1.0f                   ,  1.0f                     , 0.0f,       // Position 0
#else
            -1.0f                   , -1.0f                     , 0.0f,       // Position 1
#endif
             0.0f                   ,  scaleHeight + heightShift,                              // TexCoord 1
             0.0f                   ,  0.f                      , 0.0f,       // Color

#ifdef PORTRAIT
            -1.0f                   , -1.0f                     , 0.0f,       // Position 1
#else
             1.0f                   , -1.0f, 0.0f,                            // Position 2
#endif
             scaleWidth + widthShift,  scaleHeight + heightShift,                               // TexCoord 2
             0.0f                   ,  0.0f                     , 0.0f,       // Color

#ifdef PORTRAIT
             1.0f                   , -1.0f, 0.0f,                            // Position 2
#else
             1.0f                   ,  1.0f                     , 0.0f,       // Position 3
#endif
             scaleWidth + widthShift,  heightShift              ,                              // TexCoord 3
             0.0f                   ,  0.0f                     , 0.0f        // Color
    };



    GLushort indices[] = { 0, 1, 2, 0, 2, 3 };

    perspectiveMatrix   (__cameraAngle, (double)GLtools::getWidth()/(double)GLtools::getHeight(), 0.01, 100.0, __perspectiveMatrix);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glUseProgram                (__programObject);

    glVertexAttribPointer       (__positionLoc, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), vVertices);
    glVertexAttribPointer       (__texCoordLoc, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), &vVertices[3]);
    glVertexAttribPointer       (__colorLoc, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), &vVertices[5]);

    glEnableVertexAttribArray   (__positionLoc);
    glEnableVertexAttribArray   (__texCoordLoc);
    glEnableVertexAttribArray   (__colorLoc);

    glUniformMatrix4fv          (__mvpPLoc, 1, GL_FALSE, __mvp2);     // GL_CHECK

    glActiveTexture             (GL_TEXTURE1);
    glBindTexture               (GL_TEXTURE_2D, __textureColorId);
    glUniform1i                 (__samplerColorLoc, 1);

    glActiveTexture             (GL_TEXTURE0);
    glBindTexture               (GL_TEXTURE_2D, __textureId);
    glUniform1i                 (__samplerLoc, 0);

    glDisable                    (GL_DEPTH_TEST);
    glDrawElements              (GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, indices);

    glVertexAttribPointer       (__positionLoc, 3, GL_FLOAT, GL_FALSE, 0, aVertices);
    glVertexAttribPointer       (__texCoordLoc, 2, GL_FLOAT, GL_FALSE, 0, aTexCoords);

    glEnable                    (GL_CULL_FACE);
    glEnable                    (GL_DEPTH_TEST);

    glActiveTexture             (GL_TEXTURE1);
    glBindTexture               (GL_TEXTURE_2D, 0);
    glActiveTexture             (GL_TEXTURE0);
    glBindTexture               (GL_TEXTURE_2D, 0);

    float mvp[16];
    for(int i = 0; i < CUBE_COUNT; ++i)
    {
        multiplyMatrix(__perspectiveMatrix, __modelView[i], mvp);
        glUniformMatrix4fv          (__mvpPLoc, 1, GL_FALSE, mvp);        // GL_CHECK
        glVertexAttribPointer       (__colorLoc, 3, GL_FLOAT, GL_FALSE, 0, colorList[i % 3]);
        glDrawArrays                (GL_TRIANGLES, 0, 36);
    }
}

GLuint
Renderer::loadShader(GLenum type, const char *shaderSrc)
{
    GLuint shader;
    GLint compiled;

    shader = glCreateShader (type);

    if (shader == 0)
    {
        return 0;
    }

    // Load the shader source
    glShaderSource (shader, 1, &shaderSrc, NULL);

    // Compile the shader
    glCompileShader (shader);

    // Check the compile status
    glGetShaderiv (shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        GLint infoLen = 0;

        glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = (char*)malloc (sizeof(char) * infoLen);

            glGetShaderInfoLog (shader, infoLen, NULL, infoLog);
            AppSecureLogExceptionTag ("QrCodeRecognizer", "Error compiling shader:\n%s\n", infoLog);

            free (infoLog);
        }

        glDeleteShader (shader);
        return 0;
    }

    return shader;

}

GLuint
Renderer::loadProgram(const char *vertShaderSrc, const char *fragShaderSrc)
{
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    // Load the vertex/fragment shaders
    vertexShader = loadShader (GL_VERTEX_SHADER, vertShaderSrc);
    if (vertexShader == 0)
    {
        return 0;
    }

    fragmentShader = loadShader (GL_FRAGMENT_SHADER, fragShaderSrc);
    if (fragmentShader == 0)
    {
        glDeleteShader(vertexShader);
        return 0;
    }

    // Create the program object
    programObject = glCreateProgram ();

    if (programObject == 0)
    {
        return 0;
    }

    glAttachShader (programObject, vertexShader);
    glAttachShader (programObject, fragmentShader);

    // Link the program
    glLinkProgram (programObject);

    // Check the link status
    glGetProgramiv (programObject, GL_LINK_STATUS, &linked);

    if (!linked)
    {
        GLint infoLen = 0;

        glGetProgramiv (programObject, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = (char*)malloc (sizeof(char) * infoLen);

            glGetProgramInfoLog (programObject, infoLen, NULL, infoLog);
            AppSecureLogExceptionTag("ImageRecognizer", "Error linking program: %s", infoLog);

            free (infoLog);
        }

        glDeleteProgram (programObject);
        return 0;
    }

    // Free up no longer needed shader resources
    glDeleteShader (vertexShader);
    glDeleteShader (fragmentShader);

    return programObject;
}

GLuint
Renderer::createSimpleTexture2D(GLenum type, int width, int height)
{
    // Create a simple 2x2 texture image with four different colors
    // Texture object handle
    GLuint textureId;

    GLubyte* pixels = new GLubyte[width * height * 4];

    // Generate a texture object
    glGenTextures (1, &textureId);

    // Bind the texture object
    glBindTexture (GL_TEXTURE_2D, textureId);

    // Load the texture
    glTexImage2D (GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixels);

    // Set the filtering mode
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    delete[] pixels;

    return textureId;
}

void
Renderer::rotateMatrix(double angle, double x, double y, double z, float *R)
{
    double radians, c, s, c1, u[3], length;
    int i, j;

    radians = (angle * M_PI) / 180.0;

    c = cos(radians);
    s = sin(radians);

    c1 = 1.0 - cos(radians);

    length = sqrt(x * x + y * y + z * z);

    u[0] = x / length;
    u[1] = y / length;
    u[2] = z / length;

    for (i = 0; i < 16; i++)
    {
        R[i] = 0.0;
    }

    R[15] = 1.0;

    for (i = 0; i < 3; i++)
    {
        R[i * 4 + (i + 1) % 3] = float(u[(i + 2) % 3] * s);
        R[i * 4 + (i + 2) % 3] = float(-u[(i + 1) % 3] * s);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            R[i * 4 + j] += float(c1 * u[i] * u[j] + (i == j ? c : 0.0));
        }
    }
}

void
Renderer::perspectiveMatrix(double fovy, double aspect, double znear, double zfar, float *P)
{
    int i;
    double f;

    f = 1.0/tan(fovy * 0.5);

    for (i = 0; i < 16; i++)
    {
        P[i] = 0.0f;
    }

#ifdef PORTRAIT
    P[0]  = float(f / aspect);
    P[5]  = float(f);
#else
    P[0]  = float(f);
    P[5]  = float(f * aspect);
#endif

    P[10] = float((znear + zfar) / (znear - zfar));
    P[11] = -1.0f;
    P[14] = float((2.0 * znear * zfar) / (znear - zfar));
    P[15] = 0.0f;
}

void
Renderer::multiplyMatrix(const float *A, const float *B, float *C)
{
    int i, j, k;
    float aTmp[16];

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            aTmp[j * 4 + i] = 0.0f;

            for (k = 0; k < 4; k++)
            {
                aTmp[j * 4 + i] += A[k * 4 + i] * B[j * 4 + k];
            }
        }
    }

    for (i = 0; i < 16; i++)
    {
        C[i] = aTmp[i];
    }
}
