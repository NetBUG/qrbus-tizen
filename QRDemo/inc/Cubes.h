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

#ifndef CUBES_H_
#define CUBES_H_

/* 3D data. Vertex range -0.5..0.5 in all axes.
* Z -0.5 is near, 0.5 is far. */
const float halfSizeofCube = 0.25;
const float halfSizeofPlane = 0.5f;
const float cubeHeight = 0.5;

#define PORTRAIT


#ifdef PORTRAIT
const float leftTransform[16] = {
        0.0f, -1.0f,  0.0f, 0.0f,
       -1.0f,  0.0f,  0.0f, 0.0f,
        0.0f,  0.0f, -1.0f, 0.0f,
        0.0f,  0.0f,  0.0f, 0.2f
};
#else
const float leftTransform[16] = {
        1.0f,  0.0f,  0.0f, 0.0f,
        0.0f, -1.0f,  0.0f, 0.0f,
        0.0f,  0.0f, -1.0f, 0.0f,
        0.0f,  0.0f,  0.0f, 0.2f
};
#endif


#ifdef PORTRAIT
const float rightTransform[16] = {
        0.0f, -1.0f,  0.0f, 0.0f,
       -1.0f,  0.0f,  0.0f, 0.0f,
        0.0f,  0.0f, -1.0f, 0.0f,
        0.0f,  0.0f,  0.0f, 2.0f
};
#else
const float rightTransform[16] = {
        1.0f,  0.0f,  0.0f, 0.0f,
        0.0f, -1.0f,  0.0f, 0.0f,
        0.0f,  0.0f, -1.0f, 0.0f,
        0.0f,  0.0f,  0.0f, 2.0f
};
#endif

const float aVertices[] =
{
    /* Front face. */
    /* Bottom left */
    -halfSizeofPlane,  halfSizeofPlane, 0,
    -halfSizeofPlane, -halfSizeofPlane, 0,
    halfSizeofPlane, -halfSizeofPlane, 0,
    /* Top right */
    -halfSizeofPlane,  halfSizeofPlane, 0,
    halfSizeofPlane, -halfSizeofPlane, 0,
    halfSizeofPlane,  halfSizeofPlane, 0,
    /* Left face */
    /* Bottom left */
    -halfSizeofCube,  halfSizeofCube,  cubeHeight,
    -halfSizeofCube, -halfSizeofCube, 0,
    -halfSizeofCube, -halfSizeofCube,  cubeHeight,
    /* Top right */
    -halfSizeofCube,  halfSizeofCube,  cubeHeight,
    -halfSizeofCube,  halfSizeofCube, 0,
    -halfSizeofCube, -halfSizeofCube, 0,
    /* Top face */
    /* Bottom left */
    -halfSizeofCube,  halfSizeofCube,  cubeHeight,
    halfSizeofCube,  halfSizeofCube, 0,
    -halfSizeofCube,  halfSizeofCube, 0,
    /* Top right */
    -halfSizeofCube,  halfSizeofCube,  cubeHeight,
    halfSizeofCube,  halfSizeofCube,  cubeHeight,
    halfSizeofCube,  halfSizeofCube, 0,
    /* Right face */
    /* Bottom left */
    halfSizeofCube,  halfSizeofCube, 0,
    halfSizeofCube, -halfSizeofCube,  cubeHeight,
    halfSizeofCube, -halfSizeofCube, 0,
    /* Top right */
    halfSizeofCube,  halfSizeofCube, 0,
    halfSizeofCube,  halfSizeofCube,  cubeHeight,
    halfSizeofCube, -halfSizeofCube,  cubeHeight,
    /* Back face */
    /* Bottom left */
    halfSizeofCube,  halfSizeofCube,  cubeHeight,
    -halfSizeofCube, -halfSizeofCube,  cubeHeight,
    halfSizeofCube, -halfSizeofCube,  cubeHeight,
    /* Top right */
    halfSizeofCube,  halfSizeofCube,  cubeHeight,
    -halfSizeofCube,  halfSizeofCube,  cubeHeight,
    -halfSizeofCube, -halfSizeofCube,  cubeHeight,
    /* Bottom face */
    /* Bottom left */
    -halfSizeofCube, -halfSizeofCube, 0,
    halfSizeofCube, -halfSizeofCube,  cubeHeight,
    -halfSizeofCube, -halfSizeofCube,  cubeHeight,
    /* Top right */
    -halfSizeofCube, -halfSizeofCube, 0,
    halfSizeofCube, -halfSizeofCube, 0,
    halfSizeofCube, -halfSizeofCube,  cubeHeight,
};


const float aTexCoords[] =
{
    /* Front face. */
    /* Bottom left */
    0.0,  1.0,
    0.0,  0.0,
    1.0,  0.0,
    /* Top right */
    0.0,  1.0,
    1.0,  0.0,
    1.0,  1.0,
    /* Left face */
    /* Bottom left */
    1.0,  1.0,
    0.0,  0.0,
    0.0,  1.0,
    /* Top right */
    1.0,  1.0,
    1.0,  0.0,
    0.0,  0.0,
    /* Top face */
    /* Bottom left */
    0.0,  1.0,
    1.0,  0.0,
    0.0,  0.0,
    /* Top right */
    0.0,  1.0,
    1.0,  1.0,
    1.0,  0.0,
    /* Right face */
    /* Bottom left */
    1.0, 0.0,
    0.0,  1.0,
    0.0, 0.0,
    /* Top right */
    1.0, 0.0,
    1.0,  1.0,
    0.0,  1.0,
    /* Back face */
    /* Bottom left */
    1.0,  1.0,
    0.0, 0.0,
    1.0, 0.0,
    /* Top right */
    1.0,  1.0,
    0.0,  1.0,
    0.0, 0.0,
    /* Bottom face */
    /* Bottom left */
    0.0, 0.0,
    1.0, 1.0,
    0.0, 1.0,
    /* Top right */
    0.0, 0.0,
    1.0, 0.0,
    1.0, 1.0
};

const float aColours[] =
{
    /* Front face */
    /* Bottom left */
	0.6f, -0.5f, 0.5f,
	0.6f, -0.5f, 0.5f,
	0.6f, -0.5f, 0.5f,
    /* Top right */
    0.6f, -0.5f, 0.5f,
    0.6f, -0.5f, 0.5f,
    0.6f, -0.5f, 0.5f,
    /* Left face */
    /* Bottom left */
    0.7f, -0.5f, 0.5f,
    0.7f, -0.5f, 0.5f,
    0.7f, -0.5f, 0.5f,
    /* Top right */
    0.7f, -0.5f, 0.5f,
    0.7f, -0.5f, 0.5f,
    0.7f, -0.5f, 0.5f,
    /* Top face */
    /* Bottom left */
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    /* Top right */
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    /* Right face */
    /* Bottom left */
    0.8f, -0.5f, 0.5f,
    0.8f, -0.5f, 0.5f,
    0.8f, -0.5f, 0.5f,
    /* Top right */
    0.8f, -0.5f, 0.5f,
    0.8f, -0.5f, 0.5f,
    0.8f, -0.5f, 0.5f,
    /* Back face */
    /* Bottom left */
    0.9f, -0.5f, 0.5f,
    0.9f, -0.5f, 0.5f,
    0.9f, -0.5f, 0.5f,
    /* Top right */
    0.9f, -0.5f, 0.5f,
    0.9f, -0.5f, 0.5f,
    0.9f, -0.5f, 0.5f,
    /* Bottom face */
    /* Bottom left */
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    /* Top right */
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
    1.f, -0.5f, 0.5f,
};

float colorList[3][36*3];


#endif /* CUBES_H_ */
