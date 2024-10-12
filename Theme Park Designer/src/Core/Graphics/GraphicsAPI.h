#ifndef GRAPHICS_API_H
#define GRAPHICS_API_H

#include <memory>

#include "Buffers/Buffer.h"
#include "Buffers/BufferLayout.h"

namespace TPD::Graphics::API
{
    /*
     * Creates a BufferLayoutElement. Offset is calculated when layout
     * is set in a VAO.
     *
     * @param index: index of the attribute in the shader.
     * @param count: number of components in the attribute.
     * @param type: shader data type of the attribute.
     * @param normalized: if the attribute is normalized.
     *
     * @return created BufferLayoutElement.
     */
    BufferLayoutElement CreateBufferLayoutElement(uint32_t index, uint32_t count, ShaderDataType type, bool normalized = false);

    /*
     * Creates a shared pointer of VertexBuffer created from the arguments.
     *
     * @param vertices: the data for the vertices that will be put in the buffer.
     * @param size: the size in bytes of the data.
     *
     * @return created shared pointer of VertexBuffer.
     */
    std::shared_ptr<VertexBuffer> CreateVertexBuffer(const float* vertices, uint32_t size);

    /*
     * Creates a shared pointer of IndexBuffer created from the arguments.
     *
     * @param indices: the order in which to draw the vertices of the associated VBO.
     * @param count: the number of indices.
     *
     * @return created shared pointer of IndexBuffer.
     */
    std::shared_ptr<IndexBuffer> CreateIndexBuffer(const uint32_t* indices, uint32_t count);

}

#endif /* GRAPHICS_API_H */