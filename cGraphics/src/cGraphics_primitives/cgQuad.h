//
//  cgQuad.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/5/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#pragma once

#include "cGraphics.h"
#include "cgVec.hpp"
#include "cgColor.h"
#include "cgVertexArray.h"
class cgQuad{
public:
    cgQuad(float* verticies, cgColor color);
    cgQuad(cgVec2* vertices,cgColor color);
    cgQuad(cgVec2 start, cgVec2 end, float width);
    ~cgQuad() {delete vao;delete [] vertBuffer;delete [] indices;};
    void draw();
private:
    cgVertexArray* vao;
    float* vertBuffer = new float[24];
    unsigned int* indices = new unsigned int[6];
};
