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
    shader = new Shader("/Users/charlescallahan/Desktop/cGraphics/cGraphics/meshShader.vs","/Users/charlescallahan/Desktop/cGraphics/cGraphics/default.fs");
    renderer = new Renderer(shader);
    
    cgVec3 verts [3] = {{0,.3,0},{.3,0,-.3},{-.3,0,-.3}};
    cgVec3 verts2 [3] = {{0,-.3,0},{.3,0,.3},{-.3,0,.3}};
    cgColor colors [3] = {{0,.3,0},{.3,0,0},{-.3,0,0}};
    cgColor colors2 [3] = {{0,.9,0},{.9,0,0},{.9,0,0}};
    
    ColoredVertex vertices[3];
    ColoredVertex vertices2[3];
    
    for (int i = 0; i < 3; i++){
        vertices[i] = ColoredVertex(verts[i], colors[i]);
        vertices2[i] = ColoredVertex(verts2[i], colors2[i]);
    }
    Triangle tr = Triangle(vertices);
    Triangle tr2 = Triangle(vertices2);
    
    mesh = new Mesh(2);
    mesh->addTriangle(tr);
    mesh->addTriangle(tr2);
    renderer->attach(*mesh, GL_DYNAMIC_DRAW);
    cgVec3 pos = cgVec3();
}
void TestWindow::draw(){
    
    projection = projectionMatrix(1, 1, 1, 2); //(float n, float r, float t, float f);
    //transform = orthoProjection(1, 1, 1, -1+pos); //(<#float n#>, <#float r#>, <#float t#>, <#float f#>)
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    std::string name = "projection";
    shader->setMat4(name, (GLfloat*) projection);
    name = "translation";
    shader->setMat4(name, (GLfloat*) trans);
    name = "rotation";
    shader->setMat4(name, (GLfloat*) rot);
    renderer->renderMesh();
    glfwSwapBuffers(window);
    cgLogOpenGLErrors();
    
    delete projection;
    delete trans;
}
void TestWindow::processInput(){
    glfwPollEvents();
    float delta = .01;
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pos.y = pos.y+delta;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pos.y = pos.y-delta;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        pos.x = pos.x-delta;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        pos.x = pos.x+delta;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        theta = theta+delta;
    this->trans = translation(pos.x,pos.y,pos.z);
    rot = rotation(pos, theta);
}
