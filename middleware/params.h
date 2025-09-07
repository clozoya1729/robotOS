#ifndef MIDDLEWARE_PARAMS_H
#define MIDDLEWARE_PARAMS_H
int params_init(void);
int param_set(const char *key, const void *val, int len);
int param_get(const char *key, void *val, int maxlen);
#endif
