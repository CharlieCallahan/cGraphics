//
//  Mesh.hpp
//  cGraphics
//
//  Created by Charles callahan on 2/20/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include "cgVec.hpp"
#include "cgColor.h"
#include "cgVertexArray.h"
#include "Texture.hpp"
#include "Shader.h"
#include <fstream>
#include <vector>

struct cgVertex{
    cgVec3 pos;
    cgVec3 norm;
    cgVec2 text;
    float texIndex = 0;
    cgVertex(cgVec3 position, cgVec3 normal, cgVec2 textPos){pos = position; norm = normal;text = textPos;}
    cgVertex(){pos = cgVec3(); norm = cgVec3();text = cgVec2();}
    void print(){std::cout << "pos: "; pos.print();std::cout<<"norm: ";norm.print();std::cout<<"text coords: "; text.print();}
};
struct Triangle{
    cgVertex vertices [3];
    Triangle(cgVertex vert1, cgVertex vert2, cgVertex vert3){vertices[0] = vert1; vertices[1] = vert2; vertices[2] = vert3;};
    Triangle(){};
    void print(){vertices[0].print();vertices[1].print();vertices[2].print();}
};
class Mesh {
public:
    Mesh();
    Mesh(std::string objFilename);
    ~Mesh(){delete transform; delete triangleData; delete texture;}
    void* getVertexData() {return (float*)triangleData;}
    int getNumVerts() {return numberTriangles*3*9;}
    void attachTexture(Texture* texture){this->texture = texture;}
    void setTexIndex(int to);
    void setTransform(cgVec3 position, cgVec3 aboutAxis, float angle);
    void setPosition(cgVec3 position){translation(position.x, position.y, position.z, *transform);}
public:
    cgMat4* transform = translation(0, 0, 0);
    Triangle* triangleData;
    int numberTriangles;
    Texture* texture;
};

#endif /* Mesh_hpp */
