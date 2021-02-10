#include "plotWindow.h"

plotWindow::plotWindow() 
: cgWindowBase(1000,600, "Plot"){
    initVAO();
    //shader = new Shader(DEFAULT_VERT_SHADER_DIR, DEFAULT_FRAG_SHADER_DIR);
    shader = new Shader();
}
void plotWindow::draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    test->draw();
    //test->rotateBy(0.02);
    //test->changeColor(cgColor(.2, cos(angle), sin(angle)));
    test->draw();
    glfwSwapBuffers(window);
}
void plotWindow::processInput()
{
    glfwPollEvents();
}
void plotWindow::initVAO()
{
    test = new cgPlotBox(cgRect(cgVec2(0, 0),cgVec2(1.9,1.9)), cgVec2(-1, 1), cgVec2(0, 1));
}   

