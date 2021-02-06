#include "plotWindow.h"

plotWindow::plotWindow() 
: cgWindowBase(1000,600){
    initVAO();
    //shader = new Shader(DEFAULT_VERT_SHADER_DIR, DEFAULT_FRAG_SHADER_DIR);
    shader = new Shader();
}

void plotWindow::draw()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    cgLogOpenGLErrors();
    shader->use();
    test->draw();
//    shader->use();
//    testVAO->bind();
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    cgLogOpenGLErrors();
    
    glfwSwapBuffers(window);
}

void plotWindow::processInput()
{
    glfwPollEvents();
}

void plotWindow::initVAO()
{
    float quadVerticies[] = {
        // positions // colors
        0.8f, -0.8f, 0.0f, // bottom right
        -0.8f, -0.8f, 0.0f, // bottom left
        0.8f, 0.8f, 0.0f, //tr
        -0.8f, 0.8f, 0.0f// tl
    };
    cgColor color = cgColor(1.0f,0.0f,0.0f);
    test = new cgQuad(quadVerticies,color);
}   

