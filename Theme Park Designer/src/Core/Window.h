#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TPD
{

    class Window
    {
    public:
        Window(const std::string& title, uint32_t width, uint32_t height);
        ~Window();

        inline uint32_t GetWidth() const { return m_width; }
        inline uint32_t GetHeight() const { return m_height; }

        void SwapBuffer();
        bool IsClosed();

    private:
        const std::string& m_title;
        uint32_t m_width;
        uint32_t m_height;
        
        GLFWwindow* m_window;
    };

}

#endif /* WINDOW_H */