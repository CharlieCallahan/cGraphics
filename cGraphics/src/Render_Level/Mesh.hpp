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
#include "Renderable.hpp"

struct ColoredVertex{
    cgVec3 position = cgVec3();
    cgColor color = cgColor();
    ColoredVertex(){position = cgVec3();color = cgColor();}
    ColoredVertex(const ColoredVertex& otherVertex){position = otherVertex.position; color = otherVertex.color;}
    ColoredVertex(cgVec3 pos, cgColor color){this->position = pos;this->color = color;}
};
struct Triangle{
    ColoredVertex vertices[3];
    Triangle(ColoredVertex* vertices) {for (int i = 0; i < 3; i++){ this->vertices[i] = vertices[i];}}
};

class Mesh : public Renderable{
public:
    Mesh(int numberTriangles){vertexArray = new float[numberTriangles*3*6];};//allocates vertex array for
    ~Mesh(){delete vertexArray;};
    void addTriangle(Triangle triangle);
    virtual void* getVertexData() override {return vertexArray;}
    virtual int getNumVerts() override {return currentVertex;}
public:
    float* vertexArray;
    int numberTriangles;
    int currentVertex = 0;
};
#endif /* Mesh_hpp */
