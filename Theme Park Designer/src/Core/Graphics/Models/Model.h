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
    };

}

#endif /* MODEL_H */