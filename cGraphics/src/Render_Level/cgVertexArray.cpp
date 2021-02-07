#include "cgVertexArray.h"

cgVertexArray::cgVertexArray(const void* vertexData, unsigned int vertexCount, const void* indexData, unsigned int indexCount,GLenum drawMode)
{
    glGenVertexArrays(1, &id);
    glGenBuffers(1, &vertexBuffObj);
    glGenBuffers(1, &elementBuffObj);
    glBindVertexArray(id);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertexCount, vertexData, drawMode);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffObj);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*indexCount, indexData, drawMode);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void cgVertexArray::refreshVertexArray(const void* vertexData,
                        unsigned int vertexCount,
                        GLenum drawMode){
    glBindVertexArray(0);
    glBindVertexArray(id);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffObj);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertexCount, vertexData, drawMode);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

cgVertexArray::~cgVertexArray()
{
    glDeleteVertexArrays(1, &id);
    glDeleteBuffers(1, &vertexBuffObj);
    glDeleteBuffers(1, &elementBuffObj);
}

void cgVertexArray::bind()
{
    glBindVertexArray(id);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffObj);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffObj);
}

void cgVertexArray::setVertexAttrPointer(GLuint index, GLint count, GLenum type, GLsizei stridebytes, int offsetbytes)
{
    bind();
    glVertexAttribPointer(index, count, type, GL_FALSE, stridebytes, (void*)(offsetbytes));
    glEnableVertexAttribArray(index);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

