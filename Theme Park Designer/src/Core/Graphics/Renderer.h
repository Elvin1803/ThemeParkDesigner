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
        static void BindShader(const Graphics::Shader* shader);
        static void DrawModel(const Graphics::Camera* camera, const Graphics::Model* model);
    };

}

#endif /* RENDERER_H */