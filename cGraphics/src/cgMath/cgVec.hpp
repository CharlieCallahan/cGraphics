#ifndef cgVec_hpp
#define cgVec_hpp
#include <stdio.h>
#include "math.h"
#include <iostream>
struct cgVec2{
    float x;
    float y;
    cgVec2(){};
    cgVec2(float x,float y);
    cgVec2(const cgVec2& vector); //Copy constructor
    cgVec2 operator+(const cgVec2& vector);
    cgVec2 operator-(const cgVec2& vector);
    cgVec2 operator*(const float& scalar);
    float innerProd(const cgVec2& vector);
    cgVec2 normalized();
    cgVec2 rotatedBy(float radians);
    void rotateBy(float radians);
};
struct cgMat2{
    cgMat2(float r1c1, float r1c2,
           float r2c1, float r2c2);
    float at(int row, int col);
    cgVec2 operator*(const cgVec2& vector);
private:
    float data[4];
};
class cg2DFloatArray{
public:
    cg2DFloatArray(int numRows, int numCols);
    ~cg2DFloatArray();
    float at(int row, int col);
    void set(int row, int col, float to);
    float max();
    float min();
public:
    int numRows;
    int numCols;
private:
    float**data;
};
struct cgVec3{
    float x;
    float y;
    float z;
    cgVec3(){this->x = 0;this->y = 0;this->z = 0;};
    cgVec3(float x,float y, float z){this->x = x;this->y = y;this->z = z;};
    cgVec3(const cgVec3& vec1){x = vec1.x;y = vec1.y;z = vec1.z;}
    cgVec3 operator+(const cgVec3& vector) {return cgVec3(vector.x+x,vector.y+y,vector.z+z);}
    cgVec3 operator-(const cgVec3& vector) {return cgVec3(vector.x-x,vector.y-y,vector.z-z);}
    void normalize();
    void norm(); 
};
struct cgVec4{
    float x;
    float y;
    float z;
    float w;
    cgVec4(float x,float y, float z,float w){this->x = x;this->y = y;this->z = z;this->w = w;};
    cgVec4(){this->x = 0;this->y = 0;this->z = 0;this->w = 0;}
};
struct cgMat4{
    float data[16];
    cgMat4(float xx,float xy,float xz,float xw, float yx,float yy,float yz,float yw, float zx,float zy,float zz,float zw, float wx,float wy,float wz, float ww);
    cgMat4(){for(int i = 0; i < 16; i++){data[i] = 0;}}
    cgMat4(const cgMat4& mat){for(int i = 0; i < 16; i++){data[i] = mat.data[i];}}
    float at(int r,int c) const {return data[4*c + r];}
    void set(int r,int c, float to){data[4*c + r] = to;}
    cgMat4 operator*(const cgMat4& mat);
    void print();
};
cgMat4* translation(float Tx, float Ty, float Tz);
void translation(float Tx, float Ty, float Tz, cgMat4& mat);
cgMat4* scaling(float Sx, float Sy, float Sz);
cgMat4* rotation(cgVec3 axis, float theta);
void rotation(cgVec3 axis, float theta, cgMat4& mat);
cgMat4* projectionMatrix(float n, float r, float t, float f);
cgMat4* orthoProjection(float n, float r, float t, float f);
cgMat4* projectionMatrixSimple(float aspect, float fov, float n, float f);
#endif /* cgVec_hpp */
