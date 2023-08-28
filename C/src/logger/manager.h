#ifndef __CL_LOGGER_MANAGER_H__
#define __CL_LOGGER_MANAGER_H__

#include <stddef.h>
#include <stdint.h>

#define LOG_CPT         1 << 0
#define LOG_CPT_DEBUG   1 << 1
#define LOG_STATUS      1 << 2
#define LOG_DEBUG       1 << 3
#define LOG_AST         1 << 4
#define LOG_LLVM        1 << 5

struct logger {
    uint8_t flags;
    void (*cpt)(const char *fmt, ...);
    void (*cpt_debug)(const char *fmt, ...);
    void (*add_flags)(uint8_t flags);
    void (*remove_flags)(uint8_t flags);
    void (*success)(const char *fmt, ...);
    void (*failure)(const char *fmt, ...);
    void (*debug)(const char *fmt, ...);
    void (*ast)(const char *fmt, ...);
    void (*llvm)(const char *fmt, ...);
};

struct logger logger(void);
void log_cpt(const char *fmt, ...);
void log_cpt_debug(const char *fmt, ...);
void add_flags(uint8_t flags);
void remove_flags(uint8_t flags);
void log_success(const char *fmt, ...);
void log_failure(const char *fmt, ...);
void log_debug(const char *fmt, ...);
void log_ast(const char *fmt, ...);
void log_llvm(const char *fmt, ...);

#endif