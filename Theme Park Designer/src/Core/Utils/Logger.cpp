#include "pch.h"
#include "Logger.h"

namespace TPD::Utils
{

    Logger* Logger::m_instance = nullptr;

    Logger::Logger()
    {
        m_out = &std::cout;
    }

    Logger& Logger::GetLogger()
    {
        if (!m_instance)
        {
            m_instance = new Logger();
        }

        return *m_instance;
    }

    void Logger::SetOutputFile(const std::string& filename)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        if (filename == "stdout")
        {
            m_out = &std::cout;
        }
        else
        {
            m_outputFile = std::make_unique<std::ofstream>(filename, std::ios::app);
            m_out = m_outputFile.get();
        }
    }

    void Logger::SetLevel(LogLevel level)
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_level = level;
    }

    std::string Logger::getTimestamp()
    {
        auto now = std::chrono::system_clock::now();
        std::string formatted_time = std::format("{0:%F %T}", floor<std::chrono::seconds>(now));

        return formatted_time;
    }

}