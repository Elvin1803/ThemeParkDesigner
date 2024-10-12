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
    
    std::shared_ptr<BufferLayout> CreateBufferLayout(std::vector<BufferLayoutElement> layout)
    {
        return std::make_shared<BufferLayout>(layout);
    }

    std::unique_ptr<VertexBuffer> CreateVertexBuffer(const float* vertices, uint32_t size)
    {
        return std::make_unique<VertexBuffer>(vertices, size);
    }

    std::unique_ptr<IndexBuffer> CreateIndexBuffer(const uint32_t* indices, uint32_t count)
    {
        return std::make_unique<IndexBuffer>(indices, count);
    }

    std::unique_ptr<VertexArray> CreateVertexArray(std::shared_ptr<BufferLayout> layout, std::unique_ptr<IndexBuffer> indexBuffer, std::unique_ptr<VertexBuffer> vertexBuffer)
    {
        auto res = std::make_unique<VertexArray>();
        res->SetLayout(layout);
        res->AddVertexBuffer(std::move(vertexBuffer));
        res->AddIndexBuffer(std::move(indexBuffer));

        return res;
    }

}