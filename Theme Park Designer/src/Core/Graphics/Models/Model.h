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

        void LoadFromFile(const std::string& filePath);
        const std::unordered_map<std::string, std::unique_ptr<Mesh>>& GetMeshes() { return m_meshes;};

    private:
        std::unordered_map<std::string, std::unique_ptr<Mesh>> m_meshes;
    };

}

#endif /* MODEL_H */