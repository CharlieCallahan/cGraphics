#include "plotWindow.h"

plotWindow::plotWindow() 
: cgWindowBase(1000,600){
    initVAO();
    //shader = new Shader(DEFAULT_VERT_SHADER_DIR, DEFAULT_FRAG_SHADER_DIR);
    shader = new Shader();
}
void plotWindow::draw()
{
    angle = angle + 0.02;
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    test->rotateBy(0.02);
    test->changeColor(cgColor(.2, cos(angle), sin(angle)));
    test->draw();
    glfwSwapBuffers(window);
}
void plotWindow::processInput()
{
    glfwPollEvents();
}
void plotWindow::initVAO()
{
    cgVec2* verticies = new cgVec2 [4];
    verticies[0] = cgVec2(-.5, .5);
    verticies[1] = cgVec2(.5, .5);
    verticies[2] = cgVec2(-.5, -.5);
    verticies[3] = cgVec2(.5, -.5);
    cgColor color = cgColor(0.50f,0.50f,0.0f);
    test = new cgQuad(verticies,color);
    delete [] verticies;
}   

