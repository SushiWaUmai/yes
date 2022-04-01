#pragma once

#define CORE_LOGGER "CORE"

namespace yes
{
    namespace Logger
    {
        typedef spdlog::level::level_enum Level;

        void Create(const char *name);
        void Destroy(const char *name);
        void SetLevel(const char *name, Level level);
        void SetFormat(const char *name, const char *fmt);

        template <typename... Args>
        void Trace(const char *name, const char *fmt, Args &&...args)
        {
            spdlog::get(name)->trace(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void Debug(const char *name, const char *fmt, Args &&...args)
        {
            spdlog::get(name)->debug(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void Info(const char *name, const char *fmt, Args &&...args)
        {
            spdlog::get(name)->info(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void Warn(const char *name, const char *fmt, Args &&...args)
        {
            spdlog::get(name)->warn(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void Error(const char *name, const char *fmt, Args &&...args)
        {
            spdlog::get(name)->error(fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        void Critical(const char *name, const char *fmt, Args &&...args)
        {
            spdlog::get(name)->critical(fmt, std::forward<Args>(args)...);
        }
    } // namespace Logger
} // namespace yes
