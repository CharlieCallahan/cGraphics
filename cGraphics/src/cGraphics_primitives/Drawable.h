//
//  Drawable.h
//  cGraphics
//
//  Created by Charles callahan on 2/9/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Drawable_h
#define Drawable_h
#include "cgRect.hpp"

class Drawable{
public:
    Drawable(cgRect inRect){this->rect = inRect;};
    virtual void draw() = 0;
protected:
    cgRect rect;
};

#endif /* Drawable_h */
