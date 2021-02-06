#pragma once
#include "cGraphics.h"
class cgVertexArray
{
public:
	//vertexData must be in floats
	//indexData must be in unsigned ints
	cgVertexArray(const void* vertexData,
		unsigned int vertexCount,
		const void* indexData,
		unsigned int indexCount,
		GLenum drawMode);
	~cgVertexArray();
	void bind();
	void setVertexAttrPointer(GLuint index,
		GLint count,
		GLenum type,
		GLsizei stridebytes,
		int offsetbytes);
public:
	unsigned int id;
private:
	unsigned int vertexBuffObj;
	unsigned int elementBuffObj;
};

