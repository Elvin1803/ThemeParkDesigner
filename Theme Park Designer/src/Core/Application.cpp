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
        renderer = Graphics::API::CreateRenderer();
        auto shader = Graphics::API::CreateShader("Basic", "Basic");
        renderer->BindShader(shader);

        camera = Graphics::API::CreatePerspectiveCamera({0, 0, 1280, 720});

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            0.5f,  -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
            0.0f,  0.5f,  0.0f,  0.0f, 0.0f, 1.0f, 1.0f,
        };

        uint32_t indices[] = {
            0, 1, 2
        };

        auto layout = Graphics::API::CreateBufferLayout({
                Graphics::API::CreateBufferLayoutElement(0, 3, TPD::Graphics::ShaderDataType::Float),
                Graphics::API::CreateBufferLayoutElement(1, 4, TPD::Graphics::ShaderDataType::Float)
            });

        auto vbo = Graphics::API::CreateVertexBuffer(vertices, sizeof(vertices));
        auto ibo = Graphics::API::CreateIndexBuffer(indices, sizeof(indices));

        vao = Graphics::API::CreateVertexArray(layout, std::move(ibo), std::move(vbo));
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
            //shader->UseShader();
            //vao->Bind();
            //glDrawElements(GL_TRIANGLES, vao->GetIndicesCount(), GL_UNSIGNED_INT, nullptr);
            renderer->Draw(camera.get(), vao);

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