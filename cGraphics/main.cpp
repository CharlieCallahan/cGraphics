#include "cGraphics.h"
#include "plotWindow.h"
//#include "cgQuad.h"
//#include "cgVec.hpp"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main()
{
    plotWindow pl = plotWindow();
    pl.run();
}
