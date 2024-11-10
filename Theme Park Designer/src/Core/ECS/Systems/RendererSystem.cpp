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
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Draw for every camera every mesh
        auto cameraView = reg.view<CameraComponent>();
        auto meshView = reg.view<ModelComponent, TransformComponent>();

        for (auto& camera : cameraView)
        {
            const auto& currentCam = cameraView.get<CameraComponent>(camera);
            glViewport(currentCam.viewportRect.x, currentCam.viewportRect.y, currentCam.viewportRect.width, currentCam.viewportRect.height);

            // TODO: Make a material component and put a ShaderID in it
            const auto& shader = ::TPD::SceneManager::GetScene()->GetShaderManager().GetResourceData(0);
            shader->UseShader();
            glEnable(GL_DEPTH_TEST);
            for (const auto& entity : meshView)
            {
                const auto& [model, meshTransform] = meshView.get<ModelComponent, TransformComponent>(entity);
                const auto& temp = ::TPD::SceneManager::GetScene()->GetModelManager().GetResourceData(model.modelID);

                unsigned int mvpLoc = glGetUniformLocation(shader->GetID(), "mvp");
                glm::mat4 mvp = currentCam.projectionMatrix * currentCam.viewMatrix * meshTransform.modelMatrix;
                //glm::mat4 mvp = currentCam.projectionMatrix * currentCam.viewMatrix;

                //TPD_LOG_INFO("mvp: {}", glm::to_string(mvp));
                glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, glm::value_ptr(mvp));

                auto& meshes = temp->GetMeshes();
                for (auto const& [_, mesh] : meshes)
                {
                    const auto& vao = mesh->GetVAO();
                    vao->Bind();
                    glDrawElements(GL_TRIANGLES, vao->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
                }
            }
        }
    }
}