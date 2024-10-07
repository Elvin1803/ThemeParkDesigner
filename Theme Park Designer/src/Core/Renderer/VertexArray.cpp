#include "VertexArray.h"

namespace TPD
{
    VertexArray::VertexArray()
    {
        glCreateVertexArrays(1, &m_VAOid);
        glBindVertexArray(m_VAOid);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_VAOid);
    }

    void VertexArray::AddVertexBuffer(float* vertices, uint32_t size)
    {
        glBindVertexArray(m_VAOid);
        m_vbos.push_back(std::make_shared<VertexBuffer>(vertices, size));
    }

    void VertexArray::AddIndexBuffer(uint32_t* indices, uint32_t count)
    {
        glBindVertexArray(m_VAOid);
        m_ibos.push_back(std::make_shared<IndexBuffer>(indices, count));
    }
}