#ifndef SECURITY_CRYPTO_HAL_H
#define SECURITY_CRYPTO_HAL_H
#include <stddef.h>
int crypto_sha256(const void *data, size_t len, void *out32);
int crypto_verify_signature(const void *msg, size_t msg_len, const void *sig, size_t sig_len, const void *pub, size_t pub_len);
#endif
