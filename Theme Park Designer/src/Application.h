#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

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

        std::unique_ptr<appConfig> LoadConfig();

    private:
        std::unique_ptr<Window> m_window;
    };

}

#endif /* APPLICATION_H */