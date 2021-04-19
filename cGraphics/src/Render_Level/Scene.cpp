//
//  Scene.cpp
//  cGraphics
//
//  Created by Charles callahan on 4/17/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Scene.hpp"

void Scene::generateVAO(){
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
    
}
void Scene::render(Camera& camera){
    shader->use();
    int samplers [2] = {0,1};
    glUniform1iv(glGetUniformLocation(shader->ID,"textures"),2,samplers);
    for(int i = 0; i < meshes.size(); i++){
        meshes[i]->texture->bindUnit(i);
    }
    std::string name = "sceneTransform";
    cgMat4 sceneTrans = camera.sceneTransform();
    shader->setMat4(name, (GLfloat*) &sceneTrans);
    vao->bind();
    glDrawArrays(GL_TRIANGLES, 0, numberVerts);
}
