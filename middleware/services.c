#include "services.h"
int srv_init(void){ return 0; }
int srv_call(const char *name, const void *req, int req_len, void *resp, int resp_max){ (void)name; (void)req; (void)req_len; (void)resp; (void)resp_max; return 0; }
