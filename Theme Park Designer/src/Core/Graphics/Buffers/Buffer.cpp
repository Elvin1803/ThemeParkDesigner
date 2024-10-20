#include "Buffer.h"
#include <iostream>

namespace TPD::Graphics
{

    // Vertex Buffer
    VertexBuffer::VertexBuffer(const float* vertices, uint32_t size) 
        : Buffer(vertices, size)
    {
        glCreateBuffers(1, &m_bufferId);
        glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &m_bufferId);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_bufferId);
    }

    void VertexBuffer::Unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    // Index Buffer
    IndexBuffer::IndexBuffer(const uint32_t* indices, uint32_t count) 
        : Buffer(indices, count), m_count(count)
    {
        glCreateBuffers(1, &m_bufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_bufferId);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
    }

    void IndexBuffer::Unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}