#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include "Shaders/Shader.h"

namespace TPD::Graphics
{

    class Renderer
    {
    public:
        static void BindShader(const Graphics::Shader* shader);
    };

}

#endif /* RENDERER_H */