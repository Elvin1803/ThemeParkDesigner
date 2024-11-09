#include "pch.h"
#include "Application.h"

#include "Core/Scene/SceneManager.h"
#include "TPD/Scenes/TestScene.h"

namespace TPD
{

    Application::Application(const std::string& title)
    {
        TPD::appConfig config = LoadConfig();

        m_window = std::make_unique<Window>(title, config.width, config.height);

        TPD::SceneManager::ChangeScene(std::make_unique<TPD::TestScene>());

        // For testing purpose
    }

    Application::~Application()
    {
        glfwTerminate();
    }

    void Application::Run()
    {
        while (!m_window->IsClosed())
        {
            TPD::SceneManager::Update(0.1f);

            m_window->SwapBuffer();
        }
    }

    appConfig Application::LoadConfig()
    {
        /* TODO: Load config from a file */

        // Generate a default config
        appConfig config{};
        config.mode = windowMode::WINDOWED;
        config.width = 1280;
        config.height = 720;

        return config;
    }
}