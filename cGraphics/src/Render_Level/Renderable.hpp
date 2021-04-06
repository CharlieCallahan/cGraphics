//
//  Renderable.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include <stdio.h>
class Renderable{
public:
    virtual void* getVertexData()=0;
    virtual int getNumVerts()=0;
};
#endif /* Renderable_hpp */
