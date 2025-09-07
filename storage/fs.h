#ifndef STORAGE_FS_H
#define STORAGE_FS_H
#include <stddef.h>
int fs_init(void);
int fs_write(const char *path, const void *data, size_t len);
int fs_read(const char *path, void *data, size_t maxlen);
#endif
