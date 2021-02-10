#include "cgVec.hpp"
cgVec2::cgVec2(float x,float y){
    this->x = x;
    this->y = y;
}
cgVec2::cgVec2(const cgVec2& vector){
    x = vector.x;
    y = vector.y;
}
cgVec2 cgVec2::operator+(const cgVec2& vector){
    return cgVec2(this->x+vector.x, this->y+vector.y);
}
cgVec2 cgVec2::operator-(const cgVec2& vector){
    return cgVec2(this->x-vector.x, this->y-vector.y);
}
cgVec2 cgVec2::operator*(const float& scalar){
    return cgVec2(this->x*scalar,this->y*scalar);
}
float cgVec2::innerProd(const cgVec2& vector){
    return this->x+vector.x + this->y*vector.y;
}
cgVec2 cgVec2::normalized(){
    float norm = sqrt(x*x+y*y);
    return cgVec2(x/norm,y/norm);
}
cgVec2 cgVec2::rotatedBy(float radians){
    cgMat2 R = cgMat2(cos(radians), -1*sin(radians), sin(radians), cos(radians));
    return R*(*this);
}
void cgVec2::rotateBy(float radians){
    cgMat2 R = cgMat2(cos(radians), -1*sin(radians), sin(radians), cos(radians));
    cgVec2 temp = R*(*this);
    this->x = temp.x;
    this->y = temp.y;
}
cgMat2::cgMat2(float r1c1, float r1c2,
               float r2c1, float r2c2){
    this->data[0] = r1c1;
    this->data[1] = r1c2;
    this->data[2] = r2c1;
    this->data[3] = r2c2;
}
float cgMat2::at(int row, int col){
    return data[row*2 + col];
}
cgVec2 cgMat2::operator*(const cgVec2& vector){
    return cgVec2(data[0]*vector.x+data[1]*vector.y, data[2]*vector.x+data[3]*vector.y);
}
