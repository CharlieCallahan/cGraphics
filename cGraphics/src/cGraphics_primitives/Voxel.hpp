//
//  Voxel.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Voxel_hpp
#define Voxel_hpp

#include <stdio.h>
#include "cgVec.hpp"
#include "Mesh.hpp"

class Voxel{
public:
    Voxel(cgVec3 center, float sideLength);
    void addToMesh(Mesh& mesh) {for (int i = 0; i < 12; i++){mesh.addTriangle(triangles[i]);}}
private:
    Triangle triangles [12];
};
#endif /* Voxel_hpp */
