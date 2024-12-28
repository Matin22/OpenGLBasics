#include "indexBuffer.h"
#include "renderer.h"
#include <iostream>

indexBuffer::indexBuffer(const unsigned int *data, unsigned int count)
    : m_Count(count)
{
    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count , data, GL_STATIC_DRAW);
}

indexBuffer::~indexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void indexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void indexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
