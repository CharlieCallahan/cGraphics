#include "plotWindow.h"
#include "cgQuad.h"
#include "cgVec.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main()
{
    plotWindow pl = plotWindow();
    pl.run();
}
