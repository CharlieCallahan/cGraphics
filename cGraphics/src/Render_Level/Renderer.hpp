//
//  Renderer.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/20/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "Mesh.hpp"
#include "Shader.h"
#include "Renderable.hpp"

class Renderer{
public:
    Renderer(Shader* shader){this->shader = shader;}
    void attach(Mesh* mesh, GLenum drawMode);
    void refreshVertices(Renderable& renderableObj,GLenum drawMode);
    ~Renderer(){delete vao;};
    void renderMesh();
private:
    int numVerts;
    cgVertexArray* vao;
    Shader* shader;
    Mesh* mesh;
};


#endif /* Renderer_hpp */
