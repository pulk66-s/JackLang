#ifndef __CL_FILES_WRITE_H__
#define __CL_FILES_WRITE_H__

#include <stdarg.h>

void write_file_fmt(const char *path, const char *fmt, va_list args);
void write_file(const char *path, const char *fmt, ...);

#endif
