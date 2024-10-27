#ifndef BUFFER_H
#define BUFFER_H

#include <glad/glad.h>

namespace TPD::Graphics
{

    class Buffer
    {
    public:
        Buffer(const void* data, uint32_t size)
            : m_bufferId(0)
        {
        }

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

    protected:
        uint32_t m_bufferId;
    };

    class VertexBuffer : public Buffer
    {
    public:
        VertexBuffer(const float* vertices, uint32_t size);
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;
    };

    class IndexBuffer : public Buffer
    {
    public:
        IndexBuffer(const uint32_t* indices, uint32_t count);
        ~IndexBuffer();

        void Bind() const;
        void Unbind() const;

        inline uint32_t GetCount() const { return m_count; }

    private:
        uint32_t m_count;
    };

}

#endif /* BUFFER_H */