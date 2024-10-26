#include "Renderer.h"

namespace TPD::Graphics
{

    void Renderer::BindShader(const Graphics::Shader* shader)
    {
        shader->UseShader();
    }

    void Renderer::DrawModel(const Graphics::Camera* camera, const Graphics::Model* model)
    {
        glViewport(camera->GetViewportRect().x, camera->GetViewportRect().y, camera->GetViewportRect().width, camera->GetViewportRect().height);

        model->GetVAO()->Bind();
        // Give MVP to shader
        glDrawElements(GL_TRIANGLES, model->GetVAO()->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }

}