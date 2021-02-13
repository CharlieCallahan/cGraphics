//
//  cgQuad.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/5/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgQuad.h"
//
//cgQuad::cgQuad(){
//    vertArray = new cgVec2[4];
//    vao = new cgVertexArray(vertBuffer, 24 , indices, 6, GL_STATIC_DRAW);
//}
cgQuad::cgQuad(cgVec2* vertices,cgColor color){
    vertArray = new cgVec2[4];
    for(int i = 0; i < 4; i++){
        vertArray[i] = vertices[i];
    }
    this->color = color;
    refreshVertBuffer();
    unsigned int temp[6] = {0,1,2,2,3,1};
    for (int i =0; i<6;i++){
        indices[i] = temp[i];
    }
    vao = new cgVertexArray(vertBuffer, 24 , indices, 6, GL_STATIC_DRAW);
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3*sizeof(float));
}
void cgQuad::refreshVertBuffer(){
    float fVerticies[12];
    fVerticies[0] = vertArray[0].x;
    fVerticies[1] = vertArray[0].y;
    fVerticies[2] = 0;
    fVerticies[3] = vertArray[1].x;
    fVerticies[4] = vertArray[1].y;
    fVerticies[5] = 0;
    fVerticies[6] = vertArray[2].x;
    fVerticies[7] = vertArray[2].y;
    fVerticies[8] = 0;
    fVerticies[9] = vertArray[3].x;
    fVerticies[10] = vertArray[3].y;
    fVerticies[11] = 0;
    for(int i = 0; i < 4;i++){
        for(int j = 0; j < 3; j++){
            vertBuffer[i*6 + j] = fVerticies[i*3+j];
            vertBuffer[i*6 + 3] = color.r;
            vertBuffer[i*6 + 4] = color.g;
            vertBuffer[i*6 + 5] = color.b;
        }
    }
}
cgQuad::cgQuad(cgRect rect, cgColor color){
    cgVec2 topLeft = cgVec2(rect.center.x - rect.size.x/2,rect.center.y + rect.size.y/2);
    cgVec2 topRight = cgVec2(rect.center.x + rect.size.x/2,rect.center.y + rect.size.y/2);
    cgVec2 bottomLeft = cgVec2(rect.center.x - rect.size.x/2,rect.center.y - rect.size.y/2);
    cgVec2 bottomRight = cgVec2(rect.center.x + rect.size.x/2,rect.center.y - rect.size.y/2);
    vertArray = new cgVec2[4];
    vertArray[0] = topLeft;
    vertArray[1] = topRight;
    vertArray[2] = bottomLeft;
    vertArray[3] = bottomRight;
    this->color = color;
    refreshVertBuffer();
    unsigned int temp[6] = {0,1,2,2,3,1};
    for (int i =0; i<6;i++){
        indices[i] = temp[i];
    }
    vao = new cgVertexArray(vertBuffer, 24 , indices, 6, GL_STATIC_DRAW);
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3*sizeof(float));
}

cgQuad::cgQuad(cgVec2 start, cgVec2 end, float width, cgColor color){
    
    cgVec2 disp = (end-start).normalized().rotatedBy(M_PI/2);
    cgVec2 cornerTopStart = start+disp*width;
    cgVec2 cornerTopEnd = end+disp*width;
    cgVec2 cornerBotStart = start-disp*width;
    cgVec2 cornerBotEnd = end-disp*width;
    vertArray = new cgVec2[4];
    vertArray[0] = cornerTopStart;
    vertArray[1] = cornerTopEnd;
    vertArray[2] = cornerBotStart;
    vertArray[3] = cornerBotEnd;
    this->color = color;
    refreshVertBuffer();
    unsigned int temp[6] = {0,1,2,2,3,1};
    for (int i =0; i<6;i++){
        indices[i] = temp[i];
    }
    vao = new cgVertexArray(vertBuffer, 24 , indices, 6, GL_STATIC_DRAW);
    vao->setVertexAttrPointer(0, 3, GL_FLOAT, 6 * sizeof(float), 0);
    vao->setVertexAttrPointer(1, 3, GL_FLOAT, 6 * sizeof(float), 3*sizeof(float));
}
void cgQuad::draw(){
     vao->bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
void cgQuad::rotateBy(float radians){
    for(int i = 0; i < 4; i++){
        vertArray[i].rotateBy(radians);
    }
    refreshVertBuffer();
    vao->refreshVertexArray(vertBuffer, 24, GL_STATIC_DRAW);
}
void cgQuad::changeColor(cgColor color){
    this->color = color;
    refreshVertBuffer();
    vao->refreshVertexArray(vertBuffer, 24, GL_STATIC_DRAW);
}
