//
//  cgQuad.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/5/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgQuad.h"

cgQuad::cgQuad(float* verticies, cgColor color){
    //topleft, topright, bottomleft, bottomright
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 3; j++){
            vertBuffer[i*6 + j] = verticies[i*3+j];
            vertBuffer[i*6 + 3] = color.r;
            vertBuffer[i*6 + 4] = color.g;
            vertBuffer[i*6 + 5] = color.b;
        }
    }
    unsigned int temp[6] = {0,1,2,2,3,1};
    for (int i =0; i<6;i++){
        indices[i] = temp[i];
    }
    vao = new cgVertexArray(vertBuffer, 24 , indices, 6, GL_STATIC_DRAW);
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3*sizeof(float));
}
cgQuad::cgQuad(cgVec2* vertices,cgColor color){
    float fVerticies[8];
    fVerticies[0] = vertices[0].x;
    fVerticies[1] = vertices[0].y;
    fVerticies[2] = vertices[1].x;
    fVerticies[3] = vertices[1].y;
    fVerticies[4] = vertices[2].x;
    fVerticies[5] = vertices[2].y;
    fVerticies[6] = vertices[3].x;
    fVerticies[7] = vertices[3].y;
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 3; j++){
            vertBuffer[i*6 + j] = fVerticies[i*3+j];
            vertBuffer[i*6 + 3] = color.r;
            vertBuffer[i*6 + 4] = color.g;
            vertBuffer[i*6 + 5] = color.b;
        }
    }
    unsigned int temp[6] = {0,1,2,2,3,1};
    for (int i =0; i<6;i++){
        indices[i] = temp[i];
    }
    vao = new cgVertexArray(vertBuffer, 24 , indices, 6, GL_STATIC_DRAW);
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3*sizeof(float));
}
cgQuad::cgQuad(cgVec2 start, cgVec2 end, float width){
    
}
void cgQuad::draw(){
    vao->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


