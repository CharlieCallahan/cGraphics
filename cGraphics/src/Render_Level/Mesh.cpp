//
//  Mesh.cpp
//  cGraphics
//
//  Created by Charles callahan on 2/20/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#include "Mesh.hpp"

Mesh::Mesh(std::string objFilename){
    FILE * file = fopen(objFilename.c_str(), "r");
    if( file == NULL ){
        std::cout << "Failed to open OBJ file: " << objFilename << "\n";
        exit(-1);
    }
    std::vector<cgVec3> tempVertPositions;
    std::vector<cgVec3> tempVertNormals;
    std::vector<cgVec2> tempTextPos;
    
    std::vector<int> vertexPosIndices;
    std::vector<int> textPosIndices;
    std::vector<int> normalIndices;
    while(1){
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.
        if ( strcmp( lineHeader, "v" ) == 0 ){
            cgVec3 vertPos;
            fscanf(file, "%f %f %f\n", &vertPos.x, &vertPos.y, &vertPos.z );
            tempVertPositions.push_back(vertPos);
        }else if ( strcmp( lineHeader, "vt" ) == 0 ){
            cgVec2 textPos;
            fscanf(file, "%f %f\n", &textPos.x, &textPos.y );
            tempTextPos.push_back(textPos);
        }else if ( strcmp( lineHeader, "vn" ) == 0 ){
            cgVec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            tempVertNormals.push_back(normal);
        }else if ( strcmp( lineHeader, "f" ) == 0 ){
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("OBJ File can't be read, Make sure that file is Triangulated \n");
                exit(-1);
            }
            vertexPosIndices.push_back(vertexIndex[0]);
            vertexPosIndices.push_back(vertexIndex[1]);
            vertexPosIndices.push_back(vertexIndex[2]);
            textPosIndices  .push_back(uvIndex[0]);
            textPosIndices  .push_back(uvIndex[1]);
            textPosIndices  .push_back(uvIndex[2]);
            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);
        }
    }
    triangleData = new Triangle [int(vertexPosIndices.size()/3)];
    numberTriangles = int(vertexPosIndices.size()/3);

    for(int i = 0; i < int(vertexPosIndices.size()/3);i++){
        cgVertex vert1 = cgVertex(tempVertPositions[vertexPosIndices[3*i]-1],tempVertNormals[ normalIndices[3*i]-1], tempTextPos[textPosIndices[3*i]-1]);

        cgVertex vert2 = cgVertex(tempVertPositions[vertexPosIndices[3*i+1]-1],tempVertNormals[ normalIndices[3*i+1]-1], tempTextPos[textPosIndices[3*i+1]-1]);

        cgVertex vert3 = cgVertex(tempVertPositions[vertexPosIndices[3*i+2]-1],tempVertNormals[ normalIndices[3*i+2]-1], tempTextPos[textPosIndices[3*i+2]-1]);
        triangleData[i] = Triangle(vert1,vert2,vert3);
                }
}
