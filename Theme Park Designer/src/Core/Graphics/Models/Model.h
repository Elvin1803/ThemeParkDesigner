#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"

namespace TPD::Graphics
{

    class Model
    {
    public:
        Model() = default;
        ~Model() = default;

        const std::unordered_map<std::string, std::unique_ptr<Mesh>>& GetMeshes() { return m_meshes;};
        void PushMesh(const std::string& name, std::unique_ptr<Mesh> mesh);

    private:
        std::unordered_map<std::string, std::unique_ptr<Mesh>> m_meshes;

        /*
         * When a new material is created, it is pushed in the scene's material manager with it's name.
         * When rendering, we get the Material with it's ID in the material manager.
         */
        std::vector<uint32_t> m_materials;
    };

}

#endif /* MODEL_H */