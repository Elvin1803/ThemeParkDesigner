#include "Application.h"

#include <memory>

namespace TPD
{
    Application::Application(const std::string& title)
    {
        auto config = LoadConfig();

        m_window = std::make_unique<Window>(title, config->width, config->height);

        // For testing purpose
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f,  -0.5f, 0.0f,
            0.0f,  0.5f,  0.0f
        };

        uint32_t indices[] = {
            0, 1, 2
        };
    }
    
    Application::~Application()
    {
        glfwTerminate();
    }
    
    void Application::Run()
    {
        while (!m_window->IsClosed())
        {
            glClearColor(1, 1, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            // render here

            m_window->SwapBuffer();
        }
    }
    
    std::unique_ptr<appConfig> Application::LoadConfig()
    {
        /* TODO: Load config from a file */

        // Generate a default config
        auto config = std::make_unique<appConfig>();

        config->mode = windowMode::WINDOWED;
        config->height = 720;
        config->width = 1280;

        return config;
    }
}