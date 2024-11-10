#include "pch.h"
#include "Model.h"

#include "ModelLoader/OBJLoader.h"

namespace TPD::Graphics
{

    void Model::PushMesh(const std::string& name, std::unique_ptr<Mesh> mesh)
    {
        m_meshes[name] = std::move(mesh);
    }

}