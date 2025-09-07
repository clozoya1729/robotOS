#include "params.h"
int params_init(void){ return 0; }
int param_set(const char *key, const void *val, int len){ (void)key; (void)val; (void)len; return 0; }
int param_get(const char *key, void *val, int maxlen){ (void)key; (void)val; (void)maxlen; return 0; }
