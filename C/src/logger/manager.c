#include "logger/manager.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

static struct logger _log = {
    .flags = LOG_SYNTAX | LOG_SYNTAX_DEBUG,
    .syntax = log_syntax,
    .add_flags = add_flags,
    .remove_flags = remove_flags,
    .syntax_debug = log_syntax_debug,
};

struct logger logger()
{
    return _log;
}

void add_flags(uint8_t flags)
{
    _log.flags |= flags;
}

void remove_flags(uint8_t flags)
{
    _log.flags &= ~flags;
}

static bool syntax_log_enabled()
{
    return _log.flags & LOG_SYNTAX;
}

static bool syntax_debug_log_enabled()
{
    return _log.flags & LOG_SYNTAX_DEBUG;
}

void log_syntax(const char *fmt, ...)
{
    if (!syntax_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void log_syntax_debug(const char *fmt, ...)
{
    if (!syntax_debug_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}
