#include "pch.h"
#include "MeshManager.h"

#include "Core/Graphics/GraphicsAPI.h"

namespace TPD
{
    uint32_t MeshManager::m_nextMeshID = 0;
    std::unordered_map<int, std::unique_ptr<MeshData>> MeshManager::m_meshMap;
    std::unordered_map<std::string, int> MeshManager::m_pathToID;

    uint32_t MeshManager::LoadMesh(const std::string& path)
    {
        // Check if mesh is already loaded
        if (m_pathToID.find(path) != m_pathToID.end())
        {
            return m_pathToID[path];  // Return existing ID
        }

        // If not loaded, load mesh from file and create a new MeshData entry
        auto newMesh = std::make_unique<MeshData>(LoadMeshFromFile(path));
        m_meshMap[m_nextMeshID] = std::move(newMesh);
        m_pathToID[path] = m_nextMeshID;
        m_nextMeshID += 1;

        return m_nextMeshID - 1;
    }

    MeshData* MeshManager::GetMesh(int id)
    {
        return m_meshMap.at(id).get();
    }

    MeshData MeshManager::LoadMeshFromFile(const std::string& path)
    {
        MeshData mesh{};

        // FIXME: Implement 3d model loader
        // Make a triangle for now
        float vertices[] = {
            -0.25f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            0.25f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
            0.0f,   0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f,
        };

        uint32_t indices[] = {
            0, 1, 2
        };

        auto layout = Graphics::API::CreateBufferLayout({
                Graphics::API::CreateBufferLayoutElement(3, TPD::Graphics::ShaderDataType::Float), // position
                Graphics::API::CreateBufferLayoutElement(4, TPD::Graphics::ShaderDataType::Float)  // color
            });

        auto vbo = Graphics::API::CreateVertexBuffer(vertices, sizeof(vertices));
        auto ibo = Graphics::API::CreateIndexBuffer(indices, sizeof(indices));

        mesh.VAO = Graphics::API::CreateVertexArray(layout, std::move(ibo), std::move(vbo));
        return mesh;
    }
}