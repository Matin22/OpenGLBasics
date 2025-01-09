#include "vertexArray.h"
#include "renderer.h"

vertexArray::vertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

vertexArray::~vertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

void vertexArray::addBuffer(const vertexBuffer &vb, const vertexBufferLayout &layout)
{
    Bind();
    vb.Bind();
    const auto &elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), reinterpret_cast<const void*>(offset));
        offset += element.count * vertexBufferElement::getSizeOfType(element.type);
    }

}

void vertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
}

void vertexArray::Unbind() const
{
    glBindVertexArray(0);
}
