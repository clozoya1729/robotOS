#ifndef SECURITY_SECURE_BOOT_H
#define SECURITY_SECURE_BOOT_H
#include <stddef.h>
int secure_boot_verify_image(const void *image, size_t len);
#endif
