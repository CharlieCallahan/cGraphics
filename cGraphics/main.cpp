#include "cGraphics.h"
#include "plotWindow.h"
//#include "cgQuad.h"
//#include "cgVec.hpp"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main()
{
    plotWindow pl = plotWindow(cgVec2(0,10), cgVec2(-10,10));
    float xdata[100];
    float ydata[100];
    float ydata1[100];
    for (int i = 0; i < 100; i++){
        xdata[i] = 2*M_PI*i/100;
        ydata[i] = sin(xdata[i]);
        ydata1[i] = cos(xdata[i]);
    }
    pl.addLine(xdata, ydata, 100);
    pl.addLine(xdata, ydata1, 100);
    pl.run();
}
