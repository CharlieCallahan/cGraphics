#include "plotWindow.h"

plotWindow::plotWindow(cgVec2 xlim, cgVec2 ylim) 
: cgWindowBase(1000,600, "Plot"){
    plotBox = new cgPlotBox(cgRect(cgVec2(0, 0),cgVec2(1.8,1.8)), xlim, ylim);
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
void plotWindow::addLine(float*ydata, int count){
    if (count > 1000){
        int plotCount = 1000;
        int gap = count/plotCount;
        float xplot[plotCount];
        float yplot[plotCount];
        for(int i = 0; i < count; i++){
            if (i%gap == 0){
                xplot[i/gap] = float(i/gap);
                yplot[i/gap] = float(ydata[i]);
            }
        }
        addLine(xplot, yplot, plotCount);
    } else {
        float xplot[count];
        for (int i = 0; i < count;i++){
            xplot[i] = float(i);
        }
        addLine(xplot, ydata, count);
    }
}
void plotWindow::addLine(double*ydata, int count){
    float yplot[count];
    for(int i = 0; i < count; i++){
        yplot[i] = float(ydata[i]);
    }
    addLine(yplot, count);
}
void plotTest(){
    plotWindow pl = plotWindow(cgVec2(0,100), cgVec2(-2,2));
    float xdata[100];
    float ydata[100];
    float ydata1[100];
    for (int i = 0; i < 100; i++){
        xdata[i] = 2*M_PI*i/100;
        ydata[i] = sin(xdata[i]);
        ydata1[i] = cos(xdata[i]);
    }
    pl.addLine(ydata, 100);
    pl.addLine(ydata1, 100);
    pl.run();
}
