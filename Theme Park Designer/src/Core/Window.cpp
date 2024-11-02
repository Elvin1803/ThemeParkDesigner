#include "pch.h"
#include "Window.h"

namespace TPD
{
    static bool isGLFWInitialized = false;

    Window::Window(const std::string& title, uint32_t width, uint32_t height)
        : m_title(title), m_width(width), m_height(height)
    {
        if (!isGLFWInitialized)
        {
            if (!glfwInit())
            {
                TPD_LOG_FATAL("GLFW could not be initialized !");
            }

            isGLFWInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

        if (m_window == nullptr)
        {
            TPD_LOG_FATAL("Failed to create window !");
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);

        // Create OpenGL context
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            TPD_LOG_FATAL("Failed to initialize GLAD !");
        }
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
    }

    void Window::SwapBuffer()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
    
    bool Window::IsClosed()
    {
        return glfwWindowShouldClose(m_window);
    }
}