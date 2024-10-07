#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>
#include <memory>
#include <vector>

#include "Buffer.h"

namespace TPD
{

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void AddVertexBuffer(float* vertices, uint32_t size);
        void AddIndexBuffer(uint32_t* indices, uint32_t count);

        inline uint32_t GetVAOid() const { return m_VAOid; };

    private:
        uint32_t m_VAOid;

        std::vector< std::shared_ptr<VertexBuffer>> m_vbos;
        std::vector< std::shared_ptr<IndexBuffer>> m_ibos;
    };

}

#endif /* VERTEX_ARRAY_H */