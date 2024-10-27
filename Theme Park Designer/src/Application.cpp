#include "pch.h"
#include "Application.h"

#include "Core/Scene/SceneManager.h"
#include "TPD/Scenes/TestScene.h"

namespace TPD
{

    Application::Application(const std::string& title)
    {
        TPD::appConfig config;
        LoadConfig(config);

        m_window = std::make_unique<Window>(title, config.width, config.height);

        TPD::SceneManager::ChangeScene(std::make_unique<TPD::TestScene>());

        // For testing purpose
        /*
        shader = Graphics::API::CreateShader("Basic", "Basic");

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
        */
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

            TPD::SceneManager::GetScene()->Update();

            /*
            Graphics::Renderer::BindShader(shader.get());
            */

            m_window->SwapBuffer();
        }
    }

    void Application::LoadConfig(TPD::appConfig& config)
    {
        /* TODO: Load config from a file */

        // Generate a default config
        config.mode = windowMode::WINDOWED;
        config.width = 1280;
        config.height = 720;
    }
}