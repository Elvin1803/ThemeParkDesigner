#include "pch.h"
#include "ObjLoader.h"

#include "Core/Graphics/GraphicsAPI.h"
#include "Core/Scene/SceneManager.h"

namespace TPD::Graphics::OBJLoader
{

    static auto layout = Graphics::API::CreateBufferLayout({
            Graphics::API::CreateBufferLayoutElement(3, TPD::Graphics::ShaderDataType::Float), // position
            Graphics::API::CreateBufferLayoutElement(3, TPD::Graphics::ShaderDataType::Float), // normal
            Graphics::API::CreateBufferLayoutElement(2, TPD::Graphics::ShaderDataType::Float)  // uvCoord
        });

    void Load(const std::string& filePath)
    {
        std::ifstream file(filePath);
        if (!file.is_open())
        {
            TPD_LOG_ERROR("Could not open {} !", filePath);
            return;
        }

        std::unique_ptr<Model> model = std::make_unique<Model>();

        // TODO: Handle materials
        std::vector<float> positions;
        std::vector<float> normals;
        std::vector<float> uvCoords;

        // Final buffers
        std::vector<float> vertexBuffer;
        std::vector<uint32_t> indexBuffer;
        uint32_t i = 0;

        std::string obj_name;
        std::string line;
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string token;
            ss >> token;

            if (token == "o")
            {
                if (vertexBuffer.size() > 0)
                {
                    PushMesh(obj_name, *model, layout, vertexBuffer, indexBuffer);
                    vertexBuffer.clear();
                    indexBuffer.clear();
                    i = 0;
                }
                ss >> obj_name;
            }
            else if (token == "v")
            {
                ParseVertex(ss, positions);
            }
            else if (token == "vn")
            {
                ParseNormal(ss, normals);
            }
            else if (token == "vt")
            {
                ParseUVCoords(ss, uvCoords);
            }
            else if (token == "f")
            {
                ParseFace(ss, vertexBuffer, positions, normals, uvCoords);
                for (int j = 0; j < 3; ++j)
                {
                    indexBuffer.push_back(i);
                    i++;
                }
            }
        }

        PushMesh(obj_name, *model, layout, vertexBuffer, indexBuffer); //askip ca marche pas

        std::string name = std::filesystem::path(filePath).replace_extension().string();
        ::TPD::SceneManager::GetScene()->GetModelManager().PushResource(name, std::move(model));
    }

    void PushMesh(const std::string& name, Model& model, std::shared_ptr<Graphics::BufferLayout> layout, std::vector<float> vertexBuffer, std::vector<uint32_t> indexBuffer)
    {
        #ifdef TPD_DEBUG
        TPD_LOG_DEBUG("Pushing submesh {}", name);

        std::ostringstream oss;
        int pointIndex = 1;
        for (size_t i = 0; i < vertexBuffer.size(); i += 8)
        {
            oss << "Point " << pointIndex << " { "
                << "position: (" << vertexBuffer[i] << ", " << vertexBuffer[i + 1] << ", " << vertexBuffer[i + 2] << "), "
                << "normals: (" << vertexBuffer[i + 3] << ", " << vertexBuffer[i + 4] << ", " << vertexBuffer[i + 5] << "), "
                << "uv: (" << vertexBuffer[i + 6] << ", " << vertexBuffer[i + 7] << ") }\n";
            pointIndex++;
        }
        oss << "Indice order:";
        for (size_t i = 0; i < indexBuffer.size(); i++)
        {
            oss << ' ' << indexBuffer[i];
        }

        TPD_LOG_DEBUG("{}", oss.str());
        #endif
        auto vbo = Graphics::API::CreateVertexBuffer(vertexBuffer.data(), sizeof(float) * vertexBuffer.size());
        auto ibo = Graphics::API::CreateIndexBuffer(indexBuffer.data(), sizeof(uint32_t) * indexBuffer.size());
        auto vao = Graphics::API::CreateVertexArray(layout, std::move(ibo), std::move(vbo));

        std::unique_ptr<Mesh> mesh = std::make_unique<Mesh>(std::move(vao));
        model.PushMesh(name, std::move(mesh));
    }

    void ParseVertex(std::stringstream& ss, std::vector<float>& data)
    {
        PushVec3(ss, data);
    }

    void ParseNormal(std::stringstream& ss, std::vector<float>& data)
    {
        PushVec3(ss, data);
    }

    void ParseUVCoords(std::stringstream& ss, std::vector<float>& data)
    {
        PushVec2(ss, data);
    }

    void ParseFace(std::stringstream& ss, std::vector<float>& vertexBuffer, std::vector<float>& positions, std::vector<float>& normals, std::vector<float>& uvCoords)
    {
        std::string point;
        for (char i = 0; i < 3; i++) // Can only take triangulated mesh
        {
            ss >> point;
            std::stringstream triplet(point);

            int v_t_n[3] = { 0, 0, 0 };
            for (char j = 0; j < 3; j++)
            {
                std::string number;
                std::getline(triplet, number, '/');
                v_t_n[j] = stoi(number);
            }

            // Vertex
            vertexBuffer.push_back(positions[(v_t_n[0] - 1) * 3 + 0]);
            vertexBuffer.push_back(positions[(v_t_n[0] - 1) * 3 + 1]);
            vertexBuffer.push_back(positions[(v_t_n[0] - 1) * 3 + 2]);

            // Normal
            vertexBuffer.push_back(normals[(v_t_n[2] - 1) * 3 + 0]);
            vertexBuffer.push_back(normals[(v_t_n[2] - 1) * 3 + 1]);
            vertexBuffer.push_back(normals[(v_t_n[2] - 1) * 3 + 2]);

            // uvCoord
            vertexBuffer.push_back(uvCoords[(v_t_n[1] - 1) * 2 + 0]);
            vertexBuffer.push_back(uvCoords[(v_t_n[1] - 1) * 2 + 1]);
        }
    }

    void PushVec3(std::stringstream& ss, std::vector<float>& data)
    {
        float x, y, z;
        ss >> x;
        ss >> y;
        ss >> z;
        data.push_back(x);
        data.push_back(y);
        data.push_back(z);
    }

    void PushVec2(std::stringstream& ss, std::vector<float>& data)
    {
        float x, y;
        ss >> x;
        ss >> y;
        data.push_back(x);
        data.push_back(y);
    }
}