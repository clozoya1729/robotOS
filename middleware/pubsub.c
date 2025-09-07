#include "pubsub.h"
int pubsub_init(void){ return 0; }
int pubsub_publish(const char *topic, const void *msg, int len){ (void)topic; (void)msg; (void)len; return 0; }
int pubsub_subscribe(const char *topic){ (void)topic; return 0; }
int pubsub_poll(const char *topic, void *msg, int maxlen){ (void)topic; (void)msg; (void)maxlen; return 0; }
