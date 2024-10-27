#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>

#include "Buffer.h"
#include "BufferLayout.h"

namespace TPD::Graphics
{

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void SetLayout(std::shared_ptr<BufferLayout> layout);

        void AddVertexBuffer(std::unique_ptr<VertexBuffer> vbo);
        void AddIndexBuffer(std::unique_ptr<IndexBuffer> ibo);

        void Bind() const;

        inline uint32_t GetVAOid() const { return m_VAOid; };
        inline uint32_t GetIndicesCount() const { return m_ibo->GetCount(); }

    private:
        uint32_t m_VAOid;
        std::shared_ptr<BufferLayout> m_layout = nullptr;

        std::unique_ptr<VertexBuffer> m_vbo = nullptr;
        std::unique_ptr<IndexBuffer> m_ibo = nullptr;
    };

}

#endif /* VERTEX_ARRAY_H */