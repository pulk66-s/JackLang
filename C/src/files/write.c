#include "files/write.h"
#include <fcntl.h>
#include <stdio.h>

void write_file_fmt(const char *path, const char *fmt, va_list args)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    va_list args_copy;

    if (fd == -1) {
        perror("open");
        return;
    }
    va_copy(args_copy, args);
    vdprintf(fd, fmt, args_copy);
    close(fd);
}

void write_file(const char *path, const char *fmt, ...)
{
    printf("write to file (%s)\n", path);
    va_list args;

    va_start(args, fmt);
    write_file_fmt(path, fmt, args);
    va_end(args);
}
