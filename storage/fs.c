#include "fs.h"
int fs_init(void){ return 0; }
int fs_write(const char *path, const void *data, size_t len){ (void)path; (void)data; (void)len; return 0; }
int fs_read(const char *path, void *data, size_t maxlen){ (void)path; (void)data; (void)maxlen; return 0; }
