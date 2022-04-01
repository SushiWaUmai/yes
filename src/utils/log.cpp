#include "core.h"
#include <cstdarg>

namespace yes
{
    namespace Logger
    {
        void Create(const char *name)
        {
            spdlog::stdout_color_mt(name);
        }

        void Flush(const char *name)
        {
            spdlog::get(name)->flush();
        }

        void Destroy(const char *name)
        {
            spdlog::drop(name);
        }

        void SetLevel(const char *name, spdlog::level::level_enum level)
        {
            spdlog::get(name)->set_level(level);
        }

        void SetFormat(const char *name, const char *fmt)
        {
            spdlog::get(name)->set_pattern(fmt);
        }
    } // namespace Logger
} // namespace yes
