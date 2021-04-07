//
//  Camera.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "cgVec.hpp"

class Camera {
public:
    Camera(float fov, float zNear, float zFar, float aspectRatio);
    Camera(float fov, float zNear, float zFar, float aspectRatio,cgVec3 pos, cgVec3 aboutAxis, float angle);
    ~Camera(){delete proj; delete trans; delete rot;}
    void setRot(cgVec3 aboutAxis, float angle);
    void setPos(cgVec3 pos);
    cgMat4 sceneTransform();
public:
    cgVec3 cameraNormal;
    cgVec3 cameraY;//y and x of normal plane to cameraNormal
    cgVec3 cameraX;
private:
    //transforms to be applied to the scene
    cgMat4* proj;
    cgMat4* trans;
    cgMat4* rot;
};
#endif /* Camera_hpp */
