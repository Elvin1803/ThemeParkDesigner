#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <GLFW/glfw3.h>

namespace TPD
{

    class Window
    {
    public:
        Window(const std::string& title, uint32_t width, uint32_t height);
        ~Window();

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