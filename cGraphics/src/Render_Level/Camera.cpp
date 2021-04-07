//
//  Camera.cpp
//  cGraphics
//
//  Created by Charles callahan on 4/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Camera.hpp"
Camera::Camera(float fov, float zNear, float zFar, float aspectRatio){
    proj = projectionMatrixSimple(aspectRatio, fov, zNear, zFar);
    trans = translation(0, 0, 0);
    rot = rotation(cgVec3(0, 0, 1), 0);
    cameraNormal = cgVec3(0,0,1);
}
Camera::Camera(float fov, float zNear, float zFar, float aspectRatio,cgVec3 pos, cgVec3 aboutAxis, float angle){
    proj = projectionMatrixSimple(aspectRatio, fov, zNear, zFar);
    trans = translation(-pos.x, -pos.y, -pos.z);
    rot = rotation(aboutAxis, -angle);
}
void Camera::setRot(cgVec3 aboutAxis, float angle){
    rotation(aboutAxis, -angle, *rot);
    cameraNormal = cgVec3(0,0,1).matMult4(*rot);
    cameraY = cgVec3(0, 1, 0);
    cameraX = cameraNormal.crossProd(cameraY);
}
void Camera::setPos(cgVec3 pos){
    translation(-pos.x, -pos.y, pos.z, *trans);
    //need to change this to move position according to current direction.
}
cgMat4 Camera::sceneTransform(){
    return (*proj)*((*rot)*(*trans));
}
