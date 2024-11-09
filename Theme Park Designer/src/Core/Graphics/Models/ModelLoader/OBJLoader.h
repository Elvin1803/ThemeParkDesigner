#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <Core/Graphics/Models/Model.h>

namespace TPD::Graphics::OBJLoader
{

    void Load(const std::string& filePath, Model& model);

    void PushMesh(const std::string& name, Model& model, std::shared_ptr<Graphics::BufferLayout> layout, std::vector<float> vertexBuffer, std::vector<uint32_t> indexBuffer);
    void ParseVertex(std::stringstream& ss, std::vector<float>& data);
    void ParseNormal(std::stringstream& ss, std::vector<float>& data);
    void ParseUVCoords(std::stringstream& ss, std::vector<float>& data);
    void ParseFace(std::stringstream& ss, std::vector<float>& vertexBuffer, std::vector<float>& positions, std::vector<float>& normals, std::vector<float>& uvCoords);
    void PushVec3(std::stringstream& ss, std::vector<float>& data);
    void PushVec2(std::stringstream& ss, std::vector<float>& data);

}

#endif /* OBJ_LOADER_H */