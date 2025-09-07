#ifndef MIDDLEWARE_SERVICES_H
#define MIDDLEWARE_SERVICES_H
int srv_init(void);
int srv_call(const char *name, const void *req, int req_len, void *resp, int resp_max);
#endif
