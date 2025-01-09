#pragma once

#include <vector>
#include <GLAD/glad.h>
#include "renderer.h"

struct vertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }

        ASSERT(false); // error-handling mechanism
        return 0;
    }

    vertexBufferElement(unsigned int t, unsigned int c, bool n)
        : type(t), count(c), normalized(n) {}
};

class vertexBufferLayout {
private:
    std::vector<vertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    vertexBufferLayout()
        : m_Stride(0) {}

    template<typename T>
    void Push(unsigned int count) {
        static_assert(false, "Unsupported type for vertex buffer layout.");
    }

    inline const std::vector<vertexBufferElement>& GetElements() const { 
        return m_Elements; 
    }

    inline unsigned int GetStride() const { 
        return m_Stride; 
    }
};

template<>
inline void vertexBufferLayout::Push<float>(unsigned int count) {
    m_Elements.push_back({GL_FLOAT, count, GL_FALSE});
    m_Stride += count * vertexBufferElement::getSizeOfType(GL_FLOAT);
}

template<>
inline void vertexBufferLayout::Push<unsigned int>(unsigned int count) {
    m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE});
    m_Stride += count * vertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
inline void vertexBufferLayout::Push<unsigned char>(unsigned int count) {
    m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    m_Stride += count * vertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
}