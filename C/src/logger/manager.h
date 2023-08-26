#ifndef __CL_LOGGER_MANAGER_H__
#define __CL_LOGGER_MANAGER_H__

#include <stddef.h>
#include <stdint.h>

#define LOG_SYNTAX          1 << 0
#define LOG_SYNTAX_DEBUG    1 << 1
#define LOG_STATUS          1 << 2

struct logger {
    uint8_t flags;
    void (*syntax)(const char *fmt, ...);
    void (*syntax_debug)(const char *fmt, ...);
    void (*add_flags)(uint8_t flags);
    void (*remove_flags)(uint8_t flags);
    void (*success)(const char *fmt, ...);
    void (*failure)(const char *fmt, ...);
};

struct logger logger(void);
void log_syntax(const char *fmt, ...);
void log_syntax_debug(const char *fmt, ...);
void add_flags(uint8_t flags);
void remove_flags(uint8_t flags);
void log_success(const char *fmt, ...);
void log_failure(const char *fmt, ...);

#endif