#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include "Model/Model.h"
#include "Camera/Camera.h"
#include "Shaders/Shader.h"

namespace TPD::Graphics
{

    class Renderer
    {
    public:
        Renderer() = default;
        ~Renderer() = default;

        void BindShader(std::shared_ptr<Graphics::Shader> shader);
        void DrawModel(const Graphics::Camera* camera, const std::unique_ptr<Graphics::Model>& model);

    private:
        std::shared_ptr<Graphics::Shader> m_shader = nullptr;
    };

}

#endif /* RENDERER_H */