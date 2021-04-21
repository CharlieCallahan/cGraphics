//
//  Batch.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/17/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Batch_hpp
#define Batch_hpp

#include <stdio.h>
#include <vector>
#include "Mesh.hpp"
#include "Camera.hpp"

class Batch{
    //Contains all meshes in a Batch to be rendered
    //Handles batch rendering and lighting
    //Supports up to 16 meshes and textures
public:
    Batch(Shader* shader){this->shader = shader;};
    ~Batch(){delete vao;}
    void render(Camera& camera);
    void addMesh(Mesh* mesh); //Batch handles mesh deletion
    void generateVAO(); //call after attaching all meshes and before rendering
    void refreshMesh(int index); //refreshes vertices, number of vertices must remain constant
private:
    std::vector<Mesh*> meshes;
    cgVertexArray* vao;
    Shader* shader;
    int numberVerts;
    int samplers[16];
};
#endif /* Batch_hpp */
