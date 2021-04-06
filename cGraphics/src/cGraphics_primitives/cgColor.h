//
//  cgColor.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/4/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef cgColor_h
#define cgColor_h

struct cgColor{
    cgColor(){this->r = 0; this->g = 0; this->b = 1;}
    cgColor(float r, float g, float b){this->r = r; this->g = g; this->b = b;}
    cgColor(const cgColor& color) {this->r = color.r; this->g = color.g; this->b = color.b;}
    float r;
    float g;
    float b;
};
#endif /* cgColor_hpp */
