#include "Renderer.h"

namespace TPD::Graphics
{

    void Renderer::BindShader(std::shared_ptr<Graphics::Shader> shader)
    {
        m_shader = shader;
    }

    void Renderer::DrawModel(const Graphics::Camera* camera, const std::unique_ptr<Graphics::Model>& model)
    {
        glViewport(camera->GetViewportRect().x, camera->GetViewportRect().y, camera->GetViewportRect().width, camera->GetViewportRect().height);

        model->GetVAO()->Bind();
        m_shader->UseShader();
        // Give MVP to shader
        glDrawElements(GL_TRIANGLES, model->GetVAO()->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }

}