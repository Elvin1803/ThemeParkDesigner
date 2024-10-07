#include "Buffer.h"

namespace TPD
{
    // Vertex Buffer
    VertexBuffer::VertexBuffer(float* vertices, uint32_t size)
    {
        glCreateBuffers(1, &m_VBOid);
        glBindBuffer(GL_ARRAY_BUFFER, m_VBOid);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &m_VBOid);
    }

    // Index Buffer
    IndexBuffer::IndexBuffer(uint32_t* indices, uint32_t count)
    {
        glCreateBuffers(1, &m_IBOid);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBOid);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_IBOid);
    }
}