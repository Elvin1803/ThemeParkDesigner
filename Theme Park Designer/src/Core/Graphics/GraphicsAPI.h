#ifndef GRAPHICS_API_H
#define GRAPHICS_API_H

#include <memory>

#include "Buffers/Buffer.h"
#include "Buffers/BufferLayout.h"
#include "Buffers/VertexArray.h"
#include "Camera/PerspectiveCamera.h"
#include "Shaders/Shader.h"
#include "Renderer.h"

namespace TPD::Graphics::API
{
    /*
     * Creates a renderer.
     *
     * @return created Renderer.
     */
    std::unique_ptr<Renderer> CreateRenderer();

    /*
     * Creates a Shader.
     *
     * @param vertexScr: Specifies which vertexShader code to use.
     * @param fragmentSrc: Specifies which fragmentShader code to use.
     *
     * @return created Shader.
     */
    std::shared_ptr<Shader> CreateShader(const std::string& vertexScr, const std::string& fragmentSrc);

    /*
     * Creates a PerspectiveCamera.
     *
     * @param r: Specifies where on the screen the camera will be rendered.
     *
     * @return created PerspectiveCamera.
     */
    std::unique_ptr<PerspectiveCamera> CreatePerspectiveCamera(viewportRect r);
    
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
    BufferLayoutElement CreateBufferLayoutElement(uint32_t count, ShaderDataType type, bool normalized = false);

    /*
     * Creates a BufferLayout.
     *
     * @param index: index of the attribute in the shader.
     * @param count: number of components in the attribute.
     * @param type: shader data type of the attribute.
     * @param normalized: if the attribute is normalized.
     *
     * @return created BufferLayoutElement.
     */
    std::shared_ptr<BufferLayout> CreateBufferLayout(std::vector<BufferLayoutElement> layout);

    /*
     * Creates a unique pointer of VertexBuffer created from the arguments.
     *
     * @param vertices: the data for the vertices that will be put in the buffer.
     * @param size: the size in bytes of the data.
     *
     * @return created unique pointer of VertexBuffer.
     */
    std::unique_ptr<VertexBuffer> CreateVertexBuffer(const float* vertices, uint32_t size);

    /*
     * Creates a unique pointer of IndexBuffer created from the arguments.
     *
     * @param indices: the order in which to draw the vertices of the associated VBO.
     * @param count: the number of indices.
     *
     * @return created unique pointer of IndexBuffer.
     */
    std::unique_ptr<IndexBuffer> CreateIndexBuffer(const uint32_t* indices, uint32_t count);

    /*
     * Creates a unique pointer of VertexArray created from the arguments.
     *
     * @param indices: the order in which to draw the vertices of the associated VBO.
     * @param count: the number of indices.
     *
     * @return created unique pointer of IndexBuffer.
     */
    std::unique_ptr<VertexArray> CreateVertexArray(std::shared_ptr<BufferLayout> BufferLayout,
                                                   std::unique_ptr<IndexBuffer> indexBuffer,
                                                   std::unique_ptr<VertexBuffer> vertexBuffer);

}

#endif /* GRAPHICS_API_H */