//
//  cgLog.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgLog.hpp"

void cgLogOpenGLErrors(){
    GLenum err;
    while((err = glGetError()) != GL_NO_ERROR)
    {
        std::cout << "OpenGL Error Code: " << err << std::endl;
    }
}
