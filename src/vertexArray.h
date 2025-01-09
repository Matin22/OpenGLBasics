#pragma once

#include "vertexBuffer.h"
#include "vertexBufferLayout.h"

class vertexArray
{

    private:
        unsigned int m_RendererID;

    public:
        vertexArray();
        ~vertexArray();

        void addBuffer(const vertexBuffer &vb, const vertexBufferLayout &layout);

        void Bind() const;
        void Unbind() const;
};