#include "plotWindow.h"

plotWindow::plotWindow(cgVec2 xlim, cgVec2 ylim) 
: cgWindowBase(1000,600, "Plot"){
    //shader = new Shader(DEFAULT_VERT_SHADER_DIR, DEFAULT_FRAG_SHADER_DIR);
    plotBox = new cgPlotBox(cgRect(cgVec2(0, 0),cgVec2(1,1)), xlim, ylim);
    shader = new Shader();
}
void plotWindow::draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    plotBox->draw();
    glfwSwapBuffers(window);
}
void plotWindow::processInput()
{
    glfwPollEvents();
}
cgColor plotWindow::getNextColor(){
    int i = currentColor;
    if (currentColor == 2){
        currentColor = 0;
    }
    currentColor++;
    return colors[i];
}
void plotWindow::addLine(float* xdata, float*ydata, int count){
    plotBox->addLine(xdata, ydata, count, getNextColor());
}
