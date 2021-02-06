//
//  cgVec.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgVec.hpp"
cgVec2::cgVec2(float x,float y){
    this->x = x;
    this->y = y;
}
cgVec2 cgVec2::operator+(const cgVec2& vector){
    return cgVec2(this->x+vector.x, this->y+vector.y);
}
cgVec2 cgVec2::operator-(const cgVec2& vector){
    return cgVec2(this->x-vector.x, this->y-vector.y);
}
float cgVec2::innerProd(const cgVec2& vector){
    return this->x+vector.x + this->y*vector.y;
}
