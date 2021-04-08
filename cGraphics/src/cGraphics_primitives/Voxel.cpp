//
//  Voxel.cpp
//  cGraphics
//
//  Created by Charles callahan on 4/6/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Voxel.hpp"
Voxel::Voxel(cgVec3 center, float sideLength){
    cgVec3 corners [8];
    float hl = sideLength/2;
    corners[0] = cgVec3(center.x-hl,center.y+hl,center.z-hl);
    corners[1] = cgVec3(center.x+hl,center.y+hl,center.z-hl);
    corners[2] = cgVec3(center.x+hl,center.y+hl,center.z+hl);
    corners[3] = cgVec3(center.x-hl,center.y+hl,center.z+hl);
    corners[4] = cgVec3(center.x-hl,center.y-hl,center.z-hl);
    corners[5] = cgVec3(center.x+hl,center.y-hl,center.z-hl);
    corners[6] = cgVec3(center.x+hl,center.y-hl,center.z+hl);
    corners[7] = cgVec3(center.x-hl,center.y-hl,center.z+hl);
    cgColor color1 = cgColor(1, 0, 1);
    cgColor color2 = cgColor(0, 1, 0);
    cgColor color3 = cgColor(0, 1, 1);
    triangles[0] = Triangle(ColoredVertex(corners[0], color1),ColoredVertex(corners[1], color2),ColoredVertex(corners[4], color3));
    triangles[1] = Triangle(ColoredVertex(corners[1], color1),ColoredVertex(corners[4], color3),ColoredVertex(corners[5], color2));
    
    triangles[2] = Triangle(ColoredVertex(corners[1], color2),ColoredVertex(corners[2], color2),ColoredVertex(corners[5], color2));
    triangles[3] = Triangle(ColoredVertex(corners[5], color2),ColoredVertex(corners[2], color2),ColoredVertex(corners[6], color2));
    
    triangles[4] = Triangle(ColoredVertex(corners[2], color3),ColoredVertex(corners[3], color3),ColoredVertex(corners[7], color3));
    triangles[5] = Triangle(ColoredVertex(corners[2], color3),ColoredVertex(corners[7], color3),ColoredVertex(corners[6], color3));
    
    triangles[6] = Triangle(ColoredVertex(corners[0], color1),ColoredVertex(corners[3], color1),ColoredVertex(corners[4], color1));
    triangles[7] = Triangle(ColoredVertex(corners[4], color1),ColoredVertex(corners[3], color1),ColoredVertex(corners[7], color1));
    
    triangles[8] = Triangle(ColoredVertex(corners[4], color2),ColoredVertex(corners[7], color2),ColoredVertex(corners[5], color2));
    triangles[9] = Triangle(ColoredVertex(corners[5], color2),ColoredVertex(corners[7], color2),ColoredVertex(corners[6], color2));
    
    triangles[10] = Triangle(ColoredVertex(corners[1], color3),ColoredVertex(corners[2], color3),ColoredVertex(corners[3], color3));
    triangles[11] = Triangle(ColoredVertex(corners[0], color3),ColoredVertex(corners[1], color3),ColoredVertex(corners[3], color3));
}
