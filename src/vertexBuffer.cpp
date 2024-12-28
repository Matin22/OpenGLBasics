#include "vertexBuffer.h"
#include "renderer.h"

vertexBuffer::vertexBuffer(const void *data, unsigned int size)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

vertexBuffer::~vertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void vertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void vertexBuffer::Unbind() const
{ 
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}
