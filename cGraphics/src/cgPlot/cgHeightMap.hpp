//
//  cgHeightMap.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/13/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef cgHeightMap_hpp
#define cgHeightMap_hpp

#include <stdio.h>
#include "cgWindowBase.h"
#include "Drawable.h"
#include "cgVec.hpp"
#include "cgQuad.h"
#include "Shader.h"
class cgHeightMap: public Drawable{
public:
    cgHeightMap(cgRect inRect, cg2DFloatArray& data);
    ~cgHeightMap(){for(int i = 0; i < numQuads;i++){delete quads[i];}delete [] quads;};
    virtual void draw() override;
    cgColor colorMap(float input, float max, float min);
private:
    cgQuad** quads;
    int numQuads;
};

class cgHeightMapWindow: public cgWindowBase{
public:
    cgHeightMapWindow(cg2DFloatArray& data);
    ~cgHeightMapWindow(){delete heightMap;delete shader;};
protected:
    virtual void draw();
    virtual void processInput();
private:
    cgHeightMap* heightMap;
    Shader* shader;
};

#endif /* cgHeightMap_hpp */
