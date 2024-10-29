#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core/Window.h"

namespace TPD
{
    enum class windowMode {
        FULLSCREEN = 0,
        BORDERLESS,
        WINDOWED
    };
    
    struct appConfig 
    {
        windowMode mode;

        uint32_t height;
        uint32_t width;
    };

    class Application
    {
    public:
        Application(const std::string& title);
        ~Application();

        void Run();


    private:
        std::unique_ptr<Window> m_window;

    private:
        appConfig Application::LoadConfig();
    };

}

#endif /* APPLICATION_H */