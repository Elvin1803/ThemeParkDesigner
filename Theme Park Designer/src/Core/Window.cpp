#include "Window.h"

#include <iostream>

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
                std::cerr << "GLFW could not be initialized !\n";
            }

            isGLFWInitialized = true;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

        if (m_window == nullptr)
        {
            std::cerr << "Failed to create window !\n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);

        // Create OpenGL context
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cerr << "Failed to initialize GLAD !" << std::endl;
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