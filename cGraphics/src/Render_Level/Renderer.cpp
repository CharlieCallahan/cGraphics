//
//  Renderer.cpp
//  cGraphics
//
//  Created by Charles callahan on 4/4/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Renderer.hpp"

void Renderer::renderMesh(){
    shader->use();
    vao->bind();
    mesh->texture->bind();
    glDrawArrays(GL_TRIANGLES, 0, numVerts);
}
void Renderer::attach(Mesh* mesh, GLenum drawMode){
    vao = new cgVertexArray(mesh->getVertexData(),mesh->getNumVerts()*8, drawMode);
    numVerts = mesh->getNumVerts()*8;
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 8 * sizeof(float), 0); //vertex
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 8 * sizeof(float), 3*sizeof(float)); //normal
    vao->setVertexAttrPointer(2, 2, GL_FLOAT, 8 * sizeof(float), 6*sizeof(float)); //texture
    this->mesh = mesh;
}
void Renderer::refreshVertices(Renderable& renderableObj, GLenum drawMode){
    vao->refreshVertexArray(renderableObj.getVertexData(), renderableObj.getNumVerts(),drawMode);
    numVerts = renderableObj.getNumVerts();
}
