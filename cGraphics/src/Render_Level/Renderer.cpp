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
    glDrawArrays(GL_TRIANGLES, 0, numVerts);
}
void Renderer::attach(Mesh& mesh, GLenum drawMode){
    vao = new cgVertexArray(mesh.vertexArray,mesh.currentVertex, drawMode);
    numVerts = mesh.currentVertex;
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0); //vertex
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3*sizeof(float)); //color
}
void Renderer::refreshVertices(Renderable& renderableObj, GLenum drawMode){
    vao->refreshVertexArray(renderableObj.getVertexData(), renderableObj.getNumVerts(),drawMode);
    numVerts = renderableObj.getNumVerts();
}
