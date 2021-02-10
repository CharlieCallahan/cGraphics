//
//  cgVec.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef cgVec_hpp
#define cgVec_hpp

#include <stdio.h>
#include "math.h"

struct cgVec2{
    float x;
    float y;
    cgVec2(){};
    cgVec2(float x,float y);
    cgVec2(const cgVec2& vector); //Copy constructor
    cgVec2 operator+(const cgVec2& vector);
    cgVec2 operator-(const cgVec2& vector);
    cgVec2 operator*(const float& scalar);
    float innerProd(const cgVec2& vector);
    cgVec2 normalized();
    cgVec2 rotatedBy(float radians);
    void rotateBy(float radians);
};

struct cgMat2{
    cgMat2(float r1c1, float r1c2,
           float r2c1, float r2c2);
    float at(int row, int col);
    cgVec2 operator*(const cgVec2& vector);
private:
    float data[4];
};
#endif /* cgVec_hpp */
