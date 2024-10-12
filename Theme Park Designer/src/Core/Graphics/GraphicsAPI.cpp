#include "GraphicsAPI.h"

namespace TPD::Graphics::API
{
    BufferLayoutElement CreateBufferLayoutElement(uint32_t index, uint32_t count, ShaderDataType type, bool normalized)
    {
        BufferLayoutElement res;
        res.index = index;
        res.count = count;
        res.type = type;
        res.normalized = normalized;

        return res;
    }
    
    std::shared_ptr<VertexBuffer> CreateVertexBuffer(const float* vertices, uint32_t size)
    {
        return std::make_shared<VertexBuffer>(vertices, size);
    }

    std::shared_ptr<IndexBuffer> CreateIndexBuffer(uint32_t* indices, uint32_t count)
    {
        return std::make_shared<IndexBuffer>(indices, count);
    }

}