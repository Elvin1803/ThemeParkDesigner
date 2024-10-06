#include "Window.h"

#include <iostream>

namespace TPD
{

    Window::Window(const std::string& title, uint32_t width, uint32_t height)
        : m_title(title), m_width(width), m_height(height)
    {
        static bool isGLFWInitialized = false;

        if (!isGLFWInitialized)
        {
            if (!glfwInit())
            {
                std::cerr << "GLFW could not be initialized !\n";
                return;
            }

            isGLFWInitialized = true;
        }

        m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

        if (m_window == nullptr)
        {
            std::cerr << "Failed to create window !\n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_window);
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