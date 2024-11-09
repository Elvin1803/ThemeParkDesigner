#include "pch.h"

#include "Application.h"

int main()
{
    #ifdef TPD_DEBUG
    ::TPD::Utils::Logger::GetLogger().SetLevel(::TPD::Utils::LogLevel::WARN);
    std::filesystem::path cwd = std::filesystem::current_path();
    TPD_LOG_ERROR("Working directory: {}", cwd.string());
    #else
    ::TPD::Utils::Logger::GetLogger().SetLevel(::TPD::Utils::LogLevel::WARN);
    #endif /* TPD_DEBUG */

    TPD::Application app("Theme Park Designer");
    app.Run();

    return 0;
}