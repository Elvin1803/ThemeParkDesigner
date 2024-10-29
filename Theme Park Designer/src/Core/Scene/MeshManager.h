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
        static uint32_t LoadMesh(const std::string& path);
        static MeshData* GetMesh(int id);

    private:
        static uint32_t m_nextMeshID;
        static std::unordered_map<int, std::unique_ptr<MeshData>> m_meshMap;
        static std::unordered_map<std::string, int> m_pathToID;

    private:
        static MeshData LoadMeshFromFile(const std::string& path);
    };

}

#endif /* MESH_MANAGER_H */