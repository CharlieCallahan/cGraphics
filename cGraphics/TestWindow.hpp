//
//  TestWindow.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/4/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef TestWindow_hpp
#define TestWindow_hpp

#include <stdio.h>
#include "cgWindowBase.h"
#include "Renderer.hpp"
#include "cgLog.hpp"
class TestWindow: public cgWindowBase{
public:
    TestWindow();
    ~TestWindow(){delete renderer; delete shader; delete mesh;};
    virtual void draw() override;
    virtual void processInput() override;
private:
    Renderer* renderer;
    Shader* shader;
    Mesh* mesh;
    cgMat4* projection;
    cgMat4* rot;
    cgMat4* trans;
    cgVec3 pos;
    float theta = 0;
};
#endif /* TestWindow_hpp */
