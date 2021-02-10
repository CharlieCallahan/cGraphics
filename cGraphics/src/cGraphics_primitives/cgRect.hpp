//
//  cgRect.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/9/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef cgRect_hpp
#define cgRect_hpp

#include <stdio.h>
#include "cgVec.hpp"

struct cgRect{
    cgRect(){};
    cgRect(cgVec2 center,cgVec2 size){this->center = center;this->size = size;};
    cgVec2 center;
    cgVec2 size;
};
#endif /* cgRect_hpp */
