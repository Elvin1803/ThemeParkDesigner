#ifndef MESH_MANAGER_H
#define MESH_MANAGER_H

#include <Core/Graphics/Buffers/VertexArray.h>

namespace TPD
{

    struct MeshData
    {
        std::unique_ptr<Graphics::VertexArray> VAO;
    };
    
    class MeshManager
    {
    public:
        MeshManager() = default;
        ~MeshManager() = default;

        uint32_t LoadMesh(const std::string& path);
        MeshData* GetMesh(int id);

    private:
        uint32_t m_nextMeshID;
        std::unordered_map<int, std::unique_ptr<MeshData>> m_meshMap;
        std::unordered_map<std::string, int> m_pathToID;

    private:
        MeshData LoadMeshFromFile(const std::string& path);
    };

}

#endif /* MESH_MANAGER_H */