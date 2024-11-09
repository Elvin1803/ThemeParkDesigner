#include "pch.h"
#include "Model.h"

#include "ModelLoader/OBJLoader.h"

namespace TPD::Graphics
{

    void Model::LoadFromFile(const std::string& filePath)
    {
        std::string extension = std::filesystem::path(filePath).extension().string();

        if (extension == ".obj")
        {
            OBJLoader::Load(filePath, *this);
        }
        else
        {
            TPD_LOG_WARN("Could not load {} !", filePath);
        }
    }

    void Model::PushMesh(const std::string& name, std::unique_ptr<Mesh> mesh)
    {
        m_meshes[name] = std::move(mesh);
    }

}