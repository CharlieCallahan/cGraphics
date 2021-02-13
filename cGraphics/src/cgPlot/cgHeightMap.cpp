//
//  cgHeightMap.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/13/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "cgHeightMap.hpp"
cgHeightMap::cgHeightMap(cgRect inRect, cg2DFloatArray& data):Drawable(inRect){
    //get max and min for color map
    float dataMax = data.max();
    float dataMin = data.min();
    float blockHeight = inRect.size.y/float(data.numRows);
    float blockWidth = inRect.size.x/float(data.numCols);
    //Start in top left corner
    float currentX = inRect.center.x - inRect.size.x/2 + blockWidth/2;
    float currentY = inRect.center.y + inRect.size.y/2 + blockHeight/2;
    numQuads = data.numCols*data.numRows;
    quads = new cgQuad*[numQuads];
    for(int i = 0; i < data.numRows; i++){
        for(int j = 0; j < data.numCols; j++){
            quads[i*data.numCols+j] = new cgQuad(cgRect(cgVec2(currentX, currentY), cgVec2(blockWidth, blockHeight)), colorMap(data.at(i, j), dataMax, dataMin));
            currentX = currentX + blockWidth;
        }
        currentY = currentY - blockHeight;
        currentX = inRect.center.x - inRect.size.x/2 + blockWidth/2;
    }
    
}
void cgHeightMap::draw(){
    for(int i = 0; i < numQuads; i++){
        quads[i]->draw();
    }
}
cgColor cgHeightMap::colorMap(float input, float max, float min){
    float range = max-min;
    return cgColor((max-input)/range,1-(max-input)/range,0);
}

cgHeightMapWindow::cgHeightMapWindow(cg2DFloatArray& data): cgWindowBase(1000,600, "Height Map"){
    heightMap = new cgHeightMap(cgRect(cgVec2(0, 0), cgVec2(1, 1)), data);
    shader = new Shader();
}
void cgHeightMapWindow::draw(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    shader->use();
    heightMap->draw();
    glfwSwapBuffers(window);
};
void cgHeightMapWindow::processInput()
{
    glfwPollEvents();
}
