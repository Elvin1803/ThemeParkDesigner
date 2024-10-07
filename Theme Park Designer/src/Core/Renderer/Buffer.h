#ifndef BUFFER_H
#define BUFFER_H

#include <memory>
#include <glad/glad.h>

namespace TPD
{

    class VertexBuffer
    {
    public:
        VertexBuffer(float* vertices, uint32_t size);
        ~VertexBuffer();

    private:
        uint32_t m_VBOid;
    };

    class IndexBuffer
    {
    public:
        IndexBuffer(uint32_t* indices, uint32_t count);
        ~IndexBuffer();

    private:
        uint32_t m_IBOid;
    };

}

#endif /* BUFFER_H */