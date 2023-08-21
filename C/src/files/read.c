#include "files/read.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

size_t file_size(const char *path)
{
    struct stat st;

    if (stat(path, &st) < 0)
        return 0;
    return st.st_size;
}

char *read_file(const char *path)
{
    int fd = open(path, O_RDONLY);
    size_t size;
    char *buff;

    if (fd == -1)
        return NULL;
    size = file_size(path);
    buff = malloc(size + 1);
    if (buff == NULL)
        return NULL;
    memset(buff, 0, size + 1);
    if (read(fd, buff, size) < 0)
        return NULL;
    close(fd);
    return buff;
}
