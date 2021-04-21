//
//  TestWindow.cpp
//  cGraphics
//
//  Created by Charles callahan on 4/4/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "TestWindow.hpp"

TestWindow::TestWindow()
: cgWindowBase(1000,600, "Test Window"){
    //glEnable(GL_CULL_FACE);
    //glDepthRange(0,100);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_DEPTH_CLAMP);
    shader = new Shader("/Users/charlescallahan/Desktop/cGraphics/cGraphics/meshShader.vs","/Users/charlescallahan/Desktop/cGraphics/cGraphics/default.fs");
    camera = new Camera(fov, n, f, ar);
    cone = new Mesh("/Users/charlescallahan/Desktop/cone.obj");
    monkey = new Mesh("/Users/charlescallahan/Desktop/monkey.obj");
    donut = new Mesh("/Users/charlescallahan/Desktop/donut.obj");
    cText = new Texture("/Users/charlescallahan/Desktop/coneText.jpg");
    dText = new Texture("/Users/charlescallahan/Desktop/donut.jpg");
    mText = new Texture("/Users/charlescallahan/Desktop/monkeyText.jpg");
    donut->attachTexture(dText);
    monkey->attachTexture(mText);
    monkey->setTransform(cgVec3(1.5, 1.5, 1.5), cgVec3(0, 0, 1), 1);
    cone->attachTexture(cText);
    batch = new Batch(shader);
    batch->addMesh(cone);
    batch->addMesh(donut);
    batch->addMesh(monkey);
    batch->generateVAO();
    cgLogOpenGLErrors();
    }
void TestWindow::draw(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    meshangle+=.1;
    donut->setTransform(cgVec3(1.5, 1.5, 1.5), cgVec3(0, 0, 1), meshangle);
    cone->setTransform(cgVec3(-1.5, 1.5, 1.5), cgVec3(0, 1, 0), meshangle);
    monkey->setTransform(cgVec3(1.5, -1.5, 1.5), cgVec3(1, 0, 0), meshangle);
    batch->render(*camera);
    glfwSwapBuffers(window);
    cgLogOpenGLErrors();
}
void TestWindow::processInput(){
    glfwPollEvents();
    float delta = .05;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pos.add(camera->cameraNormal*delta);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pos.add(camera->cameraNormal*(-delta));
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        pos.add(camera->cameraX*delta);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        pos.add(camera->cameraX*(-delta));
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        pos.add(camera->cameraY*(-delta));
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        pos.add(camera->cameraY*(delta));
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        theta = theta+delta;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        theta = theta-delta;
    camera->setRot(cgVec3(0, 1, 0), theta);
    camera->setPos(pos);
    
}
