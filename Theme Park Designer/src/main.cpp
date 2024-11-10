#include "pch.h"

#include "Application.h"

int main()
{
    #ifdef TPD_DEBUG
    ::TPD::Utils::Logger::GetLogger().SetLevel(::TPD::Utils::LogLevel::INFO);
    #else
    ::TPD::Utils::Logger::GetLogger().SetLevel(::TPD::Utils::LogLevel::WARN);
    #endif /* TPD_DEBUG */

    TPD::Application app("Theme Park Designer");
    app.Run();

    return 0;
}