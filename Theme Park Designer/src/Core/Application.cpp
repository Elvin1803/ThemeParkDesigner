#include "Application.h"

namespace TPD
{
    Application::Application(const std::string& title)
        : m_title(title)
    {
        m_window = std::make_unique<Window>(title, 1280, 720);
    }
    
    Application::~Application()
    {
        glfwTerminate();
    }
    
    void Application::Run()
    {
        while (!m_window->IsClosed())
        {
            m_window->SwapBuffer();
        }
    }
}