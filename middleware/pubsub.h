#ifndef MIDDLEWARE_PUBSUB_H
#define MIDDLEWARE_PUBSUB_H
int pubsub_init(void);
int pubsub_publish(const char *topic, const void *msg, int len);
int pubsub_subscribe(const char *topic);
int pubsub_poll(const char *topic, void *msg, int maxlen);
#endif
