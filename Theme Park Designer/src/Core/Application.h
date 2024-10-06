#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include "Core/Window.h"

namespace TPD
{

    class Application
    {
    public:
        Application(const std::string& title);
        ~Application();

        void Run();

    private:
        const std::string& m_title;

        std::unique_ptr<Window> m_window;
    };

}

#endif /* APPLICATION_H */