//
//  Scene.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/17/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>
#include <vector>
#include "Mesh.hpp"
#include "Camera.hpp"

class Scene{
    //Contains all meshes in a scene to be rendered
    //Handles batch rendering and lighting
public:
    Scene(Shader* shader){this->shader = shader;};
    ~Scene(){for(int i = 0; i < meshes.size(); i++){delete meshes[i];} delete vao;}
    void render(Camera& camera);
    void addMesh(Mesh* mesh){mesh->setTexIndex(meshes.size());meshes.push_back(mesh);}; //Scene handles mesh deletion
    void generateVAO(); //call after attaching all meshes and before rendering
    void refreshMesh(int index); //refreshes vertices, number of vertices must remain constant
private:
    std::vector<Mesh*> meshes;
    cgVertexArray* vao;
    Shader* shader;
    int numberVerts;
};
#endif /* Scene_hpp */
