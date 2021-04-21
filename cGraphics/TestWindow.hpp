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
#include "cgLog.hpp"
#include "Mesh.hpp"
#include "Camera.hpp"
#include "Batch.hpp"

class TestWindow: public cgWindowBase{
public:
    TestWindow();
    ~TestWindow(){ delete shader;delete camera;delete cone; delete monkey;};
    virtual void draw() override;
    virtual void processInput() override;
private:
    Shader* shader;
    Camera* camera;
    cgVec3 pos;
    Mesh* cone;
    Mesh* monkey;
    Mesh* donut;
    Texture* cText;
    Texture* mText;
    Texture* dText;
    Batch* batch;
    float meshangle = 0;
    float theta = 0;
    float ar = 4.0/3.0;
    float fov = 1.5;
    float n = .1;
    float f = 10;
};
#endif /* TestWindow_hpp */
