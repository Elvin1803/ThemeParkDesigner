#include "pch.h"
#include "ModelLoader.h"

#include "Core/Scene/SceneManager.h"
#include "OBJLoader.h"

namespace TPD::Graphics
{

    void ModelLoader::LoadFromFile(const std::string& filePath)
    {
        std::string extension = std::filesystem::path(filePath).extension().string();

        if (extension == ".obj")
        {
            OBJLoader::Load(filePath);
        }
        else
        {
            TPD_LOG_WARN("Could not load {} !", filePath);
        }
    }

}