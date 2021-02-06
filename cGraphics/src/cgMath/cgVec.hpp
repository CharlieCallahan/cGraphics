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
    cgVec2(float x,float y);
    cgVec2 operator+(const cgVec2& vector);
    cgVec2 operator-(const cgVec2& vector);
    float innerProd(const cgVec2& vector);
};
#endif /* cgVec_hpp */
