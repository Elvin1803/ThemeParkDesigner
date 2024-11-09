#include "pch.h"
#include "Model.h"

#include "Core/Graphics/GraphicsAPI.h"

namespace TPD::Graphics
{

    void Model::LoadFromFile(const std::string& filePath)
    {
        // TODO
        // Create Square mesh
        float vertices[] = {
            -0.5f, 0.5f,  0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
            0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
            0.5f,   0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f,
        };

        uint32_t indices[] = {
            0, 1, 2, 0, 2, 3
        };

        auto layout = Graphics::API::CreateBufferLayout({
                Graphics::API::CreateBufferLayoutElement(3, TPD::Graphics::ShaderDataType::Float), // position
                Graphics::API::CreateBufferLayoutElement(4, TPD::Graphics::ShaderDataType::Float)  // color
            });

        auto vbo = Graphics::API::CreateVertexBuffer(vertices, sizeof(vertices));
        auto ibo = Graphics::API::CreateIndexBuffer(indices, sizeof(indices));
        auto square = Graphics::API::CreateVertexArray(layout, std::move(ibo), std::move(vbo));
        std::unique_ptr<Mesh> squareMesh = std::make_unique<Mesh>(std::move(square));

        m_meshes["square"] = std::move(squareMesh);
    }

}