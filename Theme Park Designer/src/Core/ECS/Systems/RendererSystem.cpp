#include "pch.h"
#include "RendererSystem.h"

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Core/ECS/Components.h"
#include "Core/Graphics/GraphicsAPI.h"

namespace TPD::ECS::RendererSystem
{
    void update(entt::registry& reg, float deltaTime)
    {
        // FIXME: find a good way to give a shader
        auto shader = Graphics::API::CreateShader("Basic", "Basic");
        shader->UseShader();

        // Draw for every camera every mesh
        auto cameraView = reg.view<CameraComponent>();
        auto meshView = reg.view<MeshComponent>();

        for (auto camera : cameraView)
        {
            auto& currentCam = cameraView.get<CameraComponent>(camera);
            glViewport(currentCam.viewportRect.x, currentCam.viewportRect.y, currentCam.viewportRect.width, currentCam.viewportRect.height);

            for (auto entity : meshView)
            {
                auto& mesh = meshView.get<MeshComponent>(entity);
                auto temp = MeshManager::GetMesh(mesh.meshID);
                temp->VAO->Bind();
                glDrawElements(GL_TRIANGLES, temp->VAO->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
            }
        }
    }
}