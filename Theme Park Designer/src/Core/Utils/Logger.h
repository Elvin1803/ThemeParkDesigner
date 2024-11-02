#ifndef LOGGER_H
#define LOGGER_H

#define TPD_LOG_INFO(...)  ::TPD::Utils::Logger::GetLogger().LogInfo(__VA_ARGS__);
#define TPD_LOG_TRACE(...) ::TPD::Utils::Logger::GetLogger().LogTrace(__VA_ARGS__);
#define TPD_LOG_DEBUG(...) ::TPD::Utils::Logger::GetLogger().LogDebug(__VA_ARGS__);
#define TPD_LOG_WARN(...)  ::TPD::Utils::Logger::GetLogger().LogWarn(__VA_ARGS__);
#define TPD_LOG_ERROR(...) ::TPD::Utils::Logger::GetLogger().LogError(__VA_ARGS__);
#define TPD_LOG_FATAL(...) ::TPD::Utils::Logger::GetLogger().LogFatal(__VA_ARGS__);

namespace TPD::Utils
{
    enum class LogLevel
    {
        INFO = 0,
        TRACE,
        DEBUG,
        WARN,
        ERROR,
        FATAL
    };

    class Logger
    {
    public:
        static Logger& GetLogger();
        void SetOutputFile(const std::string& filename);
        void SetLevel(LogLevel level);

        template<typename... Args>
        void LogInfo(const std::string& message, Args... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_level <= LogLevel::INFO)
            {
                *m_out << "[" << getTimestamp() << "][INFO] " << std::vformat(message, std::make_format_args(args...)) << "\n";
            }
        }

        template<typename... Args>
        void LogTrace(const std::string& message, Args... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_level <= LogLevel::TRACE)
            {
                *m_out << "[" << getTimestamp() << "][TRACE] " << std::vformat(message, std::make_format_args(args...)) << "\n";
            }
        }

        template<typename... Args>
        void LogDebug(const std::string& message, Args... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_level <= LogLevel::DEBUG)
            {
                *m_out << "[" << getTimestamp() << "][DEBUG] " << std::vformat(message, std::make_format_args(args...)) << "\n";
            }
        }

        template<typename... Args>
        void LogWarn(const std::string& message, Args... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_level <= LogLevel::WARN)
            {
                *m_out << "[" << getTimestamp() << "][WARN] " << std::vformat(message, std::make_format_args(args...)) << "\n";
            }
        }

        template<typename... Args>
        void LogError(const std::string& message, Args... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_level <= LogLevel::ERROR)
            {
                *m_out << "[" << getTimestamp() << "][ERROR] " << std::vformat(message, std::make_format_args(args...)) << "\n";
            }
        }

        template<typename... Args>
        void LogFatal(const std::string& message, Args... args)
        {
            std::lock_guard<std::mutex> lock(m_mutex);

            if (m_level <= LogLevel::FATAL)
            {
                *m_out << "[" << getTimestamp() << "][FATAL] " << std::vformat(message, std::make_format_args(args...)) << "\n";
            }
        }

    private:
        static Logger* m_instance;

        std::ostream* m_out;
        std::unique_ptr<std::ofstream> m_outputFile;
        LogLevel m_level = LogLevel::INFO;
        std::mutex m_mutex;

    private:
        Logger();
        ~Logger() = default;

        std::string getTimestamp();
    };

}

#endif /* LOGGER_H */