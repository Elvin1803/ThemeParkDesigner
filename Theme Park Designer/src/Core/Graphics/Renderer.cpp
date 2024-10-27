#include "pch.h"
#include "Renderer.h"

namespace TPD::Graphics
{

    void Renderer::BindShader(const Graphics::Shader* shader)
    {
        shader->UseShader();
    }

}