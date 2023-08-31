#include "logger/manager.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

static struct logger _log = {
    .flags = LOG_CPT | LOG_CPT_DEBUG | LOG_STATUS | LOG_DEBUG | LOG_AST | LOG_LLVM,
    .cpt = log_cpt,
    .add_flags = add_flags,
    .remove_flags = remove_flags,
    .cpt_debug = log_cpt_debug,
    .success = log_success,
    .failure = log_failure,
    .debug = log_debug,
    .ast = log_ast,
    .llvm = log_llvm
};

static const char *YELLOW = "\033[33m";
static const char *RED = "\033[31m";
static const char *GREEN = "\033[32m";
static const char *BLUE = "\033[34m";
static const char *RESET = "\033[0m";

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

static bool cpt_log_enabled()
{
    return _log.flags & LOG_CPT;
}

static bool cpt_debug_log_enabled()
{
    return _log.flags & LOG_CPT_DEBUG;
}

static bool status_log_enabled()
{
    return _log.flags & LOG_STATUS;
}

static bool debug_log_enabled()
{
    return _log.flags & LOG_DEBUG;
}

static bool ast_log_enabled()
{
    return _log.flags & LOG_AST;
}

static bool llvm_log_enabled()
{
    return _log.flags & LOG_LLVM;
}

void log_cpt(const char *fmt, ...)
{
    if (!cpt_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("%s[CPT]%s ", BLUE, RESET);
    vprintf(fmt, args);
    va_end(args);
}

void log_cpt_debug(const char *fmt, ...)
{
    if (!cpt_debug_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("%s[CPT_DEBUG]%s ", BLUE, RESET);
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

void log_debug(const char *fmt, ...)
{
    if (!debug_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("%s[DEBUG]%s ", YELLOW, RESET);
    vprintf(fmt, args);
    va_end(args);
}

void log_ast(const char *fmt, ...)
{
    if (!ast_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("\033[33m[AST]\033[0m ");
    vprintf(fmt, args);
    va_end(args);
}

void log_llvm(const char *fmt, ...)
{
    if (!llvm_log_enabled()) {
        return;
    }
    va_list args;
    va_start(args, fmt);
    printf("%s[LLVM]%s ", GREEN, RESET);
    vprintf(fmt, args);
    va_end(args);
}
