#ifndef STORAGE_LOG_H
#define STORAGE_LOG_H
int log_init(void);
int log_write(const char *tag, const char *msg);
#endif
