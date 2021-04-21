//
//  Batch.cpp
//  cGraphics
//
//  Created by Charles callahan on 4/17/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Batch.hpp"
void Batch::addMesh(Mesh* mesh){
#ifdef DEBUG_MODE
    if(meshes.size()>=15)
    { std::cout << "ERROR: Batch can only handle up to 16 meshes\n";
        exit(-1); }
#endif
    mesh->setTexIndex(meshes.size());meshes.push_back(mesh);
}

void Batch::generateVAO(){
    numberVerts = 0;
    for(int i = 0; i < meshes.size(); i++){
        numberVerts = numberVerts+meshes[i]->getNumVerts();
    }
    vao = new cgVertexArray(numberVerts, GL_DYNAMIC_DRAW);
    int offset = 0;
    for(int i = 0; i < meshes.size(); i++){
        vao->addSubData(offset, meshes[i]->getNumVerts()*sizeof(float), meshes[i]->getVertexData());
        offset = offset + meshes[i]->getNumVerts()*sizeof(float);
    }
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 9 * sizeof(float), 0); //vertex
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 9 * sizeof(float), 3*sizeof(float)); //normal
    vao->setVertexAttrPointer(2, 2, GL_FLOAT, 9 * sizeof(float), 6*sizeof(float)); //texture
    vao->setVertexAttrPointer(3, 1, GL_FLOAT, 9 * sizeof(float), 8*sizeof(float)); //texture index
    for(int i = 0; i < 16; i++){
        samplers[i] = i;
    }
}
void Batch::render(Camera& camera){
    shader->use();
    glUniform1iv(glGetUniformLocation(shader->ID,"textures"),16,samplers);
    cgMat4 transforms[16];
    for(int i = 0; i < meshes.size(); i++){
        meshes[i]->texture->bindUnit(i);
        transforms[i] = *(meshes[i]->transform); //this might be a source of performance issues
    }
    glUniformMatrix4fv(glGetUniformLocation(shader->ID,"modelTransforms"),16,false,(float*)transforms);
    std::string name = "sceneTransform";
    cgMat4 sceneTrans = camera.sceneTransform();
    shader->setMat4(name, (GLfloat*) &sceneTrans);
    vao->bind();
    glDrawArrays(GL_TRIANGLES, 0, numberVerts);
}
