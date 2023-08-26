#include "logger/manager.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

static struct logger _log = {
    .flags = LOG_SYNTAX | LOG_SYNTAX_DEBUG | LOG_STATUS,
    .syntax = log_syntax,
    .add_flags = add_flags,
    .remove_flags = remove_flags,
    .syntax_debug = log_syntax_debug,
    .success = log_success,
    .failure = log_failure
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

static bool status_log_enabled()
{
    return _log.flags & LOG_STATUS;
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

void log_success(const char *fmt, ...)
{
    if (!status_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("\033[32m");
    vprintf(fmt, args);
    printf("\033[0m");
    va_end(args);
}

void log_failure(const char *fmt, ...)
{
    if (!status_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("\033[31m");
    vprintf(fmt, args);
    printf("\033[0m");
    va_end(args);
}