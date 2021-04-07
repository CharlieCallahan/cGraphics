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

cg2DFloatArray::cg2DFloatArray(int numRows, int numCols){
    data = new float*[numRows];
    for (int i = 0; i < numRows; i++){
        data[i] = new float[numCols];
    }
    this->numCols = numCols;
    this->numRows = numRows;
}
cg2DFloatArray::~cg2DFloatArray(){
    for(int i = 0; i < numRows;i++){
        delete[] data[i];
    }
    delete [] data;
}
float cg2DFloatArray::at(int row, int col){
    return data[row][col];
}
void cg2DFloatArray::set(int row, int col, float to){
    this->data[row][col] = to;
}
float cg2DFloatArray::max(){
    float max = data[0][0];
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if (data[i][j] > max){
                max = data[i][j];
            }
        }
    }
    return max;
}
float cg2DFloatArray::min(){
    float min = data[0][0];
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if (data[i][j] < min){
                min = data[i][j];
            }
        }
    }
    return min;
}
//cgMat4::cgMat4(float xx,float yx,float zx,float wx, float xy,float yy,float zy,float wy, float xz,float yz,float zz,float wz, float xw,float yw,float zw, float ww){
//    x = cgVec4(xx,xy,xz,xw);
//    y = cgVec4(yx,yy,yz,yw);
//    z = cgVec4(zx,zy,zz,zw);
//    w = cgVec4(wx,wy,wz,ww);
//}
cgMat4::cgMat4(float xx,float yx,float zx,float wx,
               float xy,float yy,float zy,float wy,
               float xz,float yz,float zz,float wz,
               float xw,float yw,float zw, float ww){
    data[0] = xx; //00
    data[1] = xy; //10
    data[2] = xz; //20
    data[3] = xw; //30
    
    data[4] = yx; 
    data[5] = yy; //11
    data[6] = yz;
    data[7] = yw;
    
    data[8] =  zx;
    data[9] =  zy;
    data[10] = zz;
    data[11] = zw;

    data[12] = wx;
    data[13] = wy;
    data[14] = wz;
    data[15] = ww;
}
cgMat4 cgMat4::operator*(const cgMat4& mat){
    cgMat4 output = cgMat4();
    float sum;
    for(int i = 0; i<4;i++){
        for(int j = 0;j<4;j++){
            sum = 0;
            for(int k = 0; k < 4;k++){
                sum = sum + at(i, k)*mat.at(k,j);
            }
            output.set(i, j, sum);
        }
    }
    return output;
}
void cgMat4::print(){
    for(int i = 0; i<4;i++){
        std::cout << "|";
        for(int j = 0;j<4;j++){
            std::cout << at(i, j) << " ";
        }
        std::cout << "|\n";
    }
}
cgMat4* translation(float Tx, float Ty, float Tz){
    return new cgMat4(1, 0, 0, Tx,
                      0, 1, 0, Ty,
                      0, 0, 1, Tz,
                      0, 0, 0, 1);
}
void translation(float Tx, float Ty, float Tz, cgMat4& mat){
    mat.set(0, 3, Tx);
    mat.set(1, 3, Ty);
    mat.set(2, 3, Tz);
}
cgMat4* scaling(float Sx, float Sy, float Sz){
    return new cgMat4(Sx, 0, 0, 0,
                      0, Sy, 0, 0,
                      0, 0, Sz, 0,
                      0, 0, 0, 1);
}
cgMat4* rotation(cgVec3 axis, float theta){
    return new cgMat4(cos(theta)+axis.x*axis.x*(1-cos(theta)), axis.x*axis.y*(1-cos(theta))-axis.z*sin(theta), axis.x*axis.z*(1-cos(theta))+axis.y*sin(theta), 0,
                      
                     axis.y*axis.x*(1-cos(theta))+axis.z*sin(theta), cos(theta)+axis.y*axis.y*(1-cos(theta)), axis.y*axis.z*(1-cos(theta))-axis.x*sin(theta), 0,
                      
                     axis.z*axis.x*(1-cos(theta))-axis.y*sin(theta), axis.z*axis.y*(1-cos(theta))+axis.x*sin(theta), cos(theta)+axis.z*axis.z*(1-cos(theta)), 0,
                      
                     0, 0, 0, 1);
}
void rotation(cgVec3 axis, float theta, cgMat4& mat){
    mat.set(0, 0, cos(theta)+axis.x*axis.x*(1-cos(theta)));
    mat.set(0, 1, axis.x*axis.y*(1-cos(theta))-axis.z*sin(theta));
    mat.set(0, 2, axis.x*axis.z*(1-cos(theta))+axis.y*sin(theta));
    mat.set(0, 3, 0);
    
    mat.set(1, 0, axis.y*axis.x*(1-cos(theta))+axis.z*sin(theta));
    mat.set(1, 1, cos(theta)+axis.y*axis.y*(1-cos(theta)));
    mat.set(1, 2, axis.y*axis.z*(1-cos(theta))-axis.x*sin(theta));
    mat.set(1, 3, 0);
    
    mat.set(2, 0, axis.z*axis.x*(1-cos(theta))-axis.y*sin(theta));
    mat.set(2, 1, axis.z*axis.y*(1-cos(theta))+axis.x*sin(theta));
    mat.set(2, 2, cos(theta)+axis.z*axis.z*(1-cos(theta)));
    mat.set(2, 3, 0);
    
    mat.set(3, 0, 0);mat.set(3, 1, 0);mat.set(3, 2, 0);mat.set(3, 3, 1);
}
cgMat4* projectionMatrix(float n, float r, float t, float f){
    return new cgMat4(n/r, 0, 0, 0,
                      0, n/t, 0, 0,
                      0, 0, -(f+n)/(f-n), -2*f*n/(f-n),
                      0, 0, -1, 0);
}
cgMat4* projectionMatrixSimple(float aspect, float fov, float n, float f){
    return new cgMat4(1/(aspect*tan(fov/2)), 0, 0, 0,
                       0, 1/(aspect*tan(fov/2)), 0, 0,
                       0, 0, -(f+n)/(f-n), -1,
                      0, 0, -2*f*n/(f-n), 0);
}
cgMat4* orthoProjection(float n, float r, float t, float f){
    return new cgMat4(1/r, 0, 0, 0,
                      0, 1/t, 0, 0,
                      0, 0, -2/(f-n), -(f+n)/(f-n),
                      0, 0, 0, 1);
}

