#include "Renderer.h"

namespace TPD::Graphics
{

    void Renderer::BindShader(std::shared_ptr<Graphics::Shader> shader)
    {
        m_shader = shader;
    }

    void Renderer::Draw(const Graphics::Camera* camera, const std::unique_ptr<Graphics::VertexArray>& vao)
    {
        glViewport(camera->GetViewportRect().x, camera->GetViewportRect().y, camera->GetViewportRect().width, camera->GetViewportRect().height);

        vao->Bind();
        m_shader->UseShader();
        // Give MVP to shader
        glDrawElements(GL_TRIANGLES, vao->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }

}