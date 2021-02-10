//
//  cgQuad.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/5/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#pragma once

//#include "cGraphics.h"
#include "cgVec.hpp"
#include "cgRect.hpp"
#include "cgColor.h"
#include "cgVertexArray.h"
#include <iostream>
class cgQuad{
public:
    //cgQuad();
    cgQuad(cgVec2* vertices,cgColor color);//topleft, topright, bottomleft, bottomright
    cgQuad(cgRect rect, cgColor color);
    cgQuad(cgVec2 start, cgVec2 end, float width,cgColor color); //Makes a line segment
    ~cgQuad() {delete vao;delete[] vertArray;delete [] vertBuffer;delete [] indices;};
    void refreshVertBuffer();
    void draw();
    void rotateBy(float radians);
    void changeColor(cgColor color);
private:
    cgColor color = cgColor(0,0,0);
    cgVertexArray* vao;
    cgVec2* vertArray;
    float* vertBuffer = new float[24];
    unsigned int* indices = new unsigned int[6];
};
