#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include "Buffers/VertexArray.h"
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
        void Draw(const Graphics::Camera* camera, const std::unique_ptr<Graphics::VertexArray>& vao);

    private:
        std::shared_ptr<Graphics::Shader> m_shader = nullptr;
    };

}

#endif /* RENDERER_H */