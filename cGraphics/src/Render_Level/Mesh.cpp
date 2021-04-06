//
//  Mesh.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/20/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Mesh.hpp"
void Mesh::addTriangle(Triangle triangle){
    float* tempArr = (float*)(&triangle);
    for(int i = 0; i < 3*6; i++){
        vertexArray[currentVertex] = tempArr[i];
        currentVertex++;
    }
}
