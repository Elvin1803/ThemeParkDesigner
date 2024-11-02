#include "pch.h"
#include "RendererSystem.h"

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "Core/ECS/Components.h"
#include "Core/Graphics/GraphicsAPI.h"

namespace TPD::ECS::RendererSystem
{
    void update(entt::registry& reg, float deltaTime)
    {
        // Draw for every camera every mesh
        auto cameraView = reg.view<CameraComponent>();
        auto meshView = reg.view<MeshComponent, TransformComponent>();

        for (auto camera : cameraView)
        {
            const auto& currentCam = cameraView.get<CameraComponent>(camera);
            glViewport(currentCam.viewportRect.x, currentCam.viewportRect.y, currentCam.viewportRect.width, currentCam.viewportRect.height);

            // TODO: Make a material component and put a Shader in it
            auto shader = ::TPD::SceneManager::GetScene()->GetShaderManager().GetShader("Basic");
            shader->UseShader();
            for (auto entity : meshView)
            {
                const auto& [mesh, meshTransform] = meshView.get<MeshComponent, TransformComponent>(entity);
                auto temp = ::TPD::SceneManager::GetScene()->GetMeshManager().GetMesh(mesh.meshID);

                unsigned int mvpLoc = glGetUniformLocation(shader->GetID(), "mvp");
                glm::mat4 mvp = currentCam.projectionMatrix * currentCam.viewMatrix * meshTransform.modelMatrix;
                glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

                temp->VAO->Bind();
                glDrawElements(GL_TRIANGLES, temp->VAO->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
            }
        }
    }
}