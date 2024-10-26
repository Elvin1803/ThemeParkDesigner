#include "Application.h"

#include <memory>
#include <iostream>

namespace TPD
{

    Application::Application(const std::string& title)
    {
        auto config = LoadConfig();

        m_window = std::make_unique<Window>(title, config->width, config->height);

        // For testing purpose
        shader = Graphics::API::CreateShader("Basic", "Basic");

        camera = Graphics::API::CreatePerspectiveCamera({0, 0, m_window->GetWidth(), m_window->GetHeight()});

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
            0.0f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f,
        };

        uint32_t indices[] = {
            0, 1, 2
        };

        auto layout = Graphics::API::CreateBufferLayout({
                Graphics::API::CreateBufferLayoutElement(3, TPD::Graphics::ShaderDataType::Float), // position
                Graphics::API::CreateBufferLayoutElement(4, TPD::Graphics::ShaderDataType::Float)  // color
            });

        auto vbo = Graphics::API::CreateVertexBuffer(vertices, sizeof(vertices));
        auto ibo = Graphics::API::CreateIndexBuffer(indices, sizeof(indices));

        auto vao = Graphics::API::CreateVertexArray(layout, std::move(ibo), std::move(vbo));

        model = std::make_unique<Graphics::Model>(vao);
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

            Graphics::Renderer::BindShader(shader.get());
            Graphics::Renderer::DrawModel(camera.get(), model.get());

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