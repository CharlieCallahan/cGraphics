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
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_CLAMP);
    shader = new Shader("/Users/charlescallahan/Desktop/cGraphics/cGraphics/meshShader.vs","/Users/charlescallahan/Desktop/cGraphics/cGraphics/default.fs");
    renderer = new Renderer(shader);
    camera = new Camera(fov, n, f, ar);
    mesh = new Mesh("/Users/charlescallahan/Desktop/monkey.obj");
    texture = new Texture("/Users/charlescallahan/Desktop/monkeyText.jpg");
    mesh->attachTexture(texture);
    renderer->attach(mesh, GL_DYNAMIC_DRAW);
}
void TestWindow::draw(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    std::string name = "sceneTransform";
    cgMat4 sceneTrans = camera->sceneTransform();
    shader->setMat4(name, (GLfloat*) &sceneTrans);
    renderer->renderMesh();
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
//    std::cout << "pos: ";
//    pos.print();
//    std::cout << "normal: ";
//    camera->cameraNormal.print();
//    std::cout << "X: ";
//    camera->cameraX.print();
    camera->setRot(cgVec3(0, 1, 0), theta);
    camera->setPos(pos);
    
}
