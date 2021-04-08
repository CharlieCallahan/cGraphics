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
#include "Voxel.hpp"
#include "Camera.hpp"

class TestWindow: public cgWindowBase{
public:
    TestWindow();
    ~TestWindow(){delete renderer; delete shader; delete mesh;delete camera;};
    virtual void draw() override;
    virtual void processInput() override;
private:
    Renderer* renderer;
    Shader* shader;
    Mesh* mesh;
    Camera* camera;
    cgVec3 pos;
    float theta = 0;
    float ar = 1/.6;
    float fov = 1.5;
    float n = .3;
    float f = 5000;
    
};
#endif /* TestWindow_hpp */
