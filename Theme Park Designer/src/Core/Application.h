#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "Core/Window.h"
#include "Graphics/GraphicsAPI.h"
#include "Graphics/Shaders/Shader.h"
#include "Graphics/Camera/PerspectiveCamera.h"

namespace TPD
{
    enum class windowMode {
        FULLSCREEN = 0,
        BORDERLESS,
        WINDOWED
    };
    
    struct appConfig 
    {
        windowMode mode;

        uint32_t height;
        uint32_t width;
    };

    class Application
    {
    public:
        Application(const std::string& title);
        ~Application();

        void Run();

        std::unique_ptr<appConfig> LoadConfig();

    private:
        std::unique_ptr<Window> m_window;

        // For testing purposes:
        std::unique_ptr<Graphics::Renderer> renderer;
        std::unique_ptr<Graphics::PerspectiveCamera> camera;
        std::unique_ptr<Graphics::VertexArray> vao;
    };

}

#endif /* APPLICATION_H */