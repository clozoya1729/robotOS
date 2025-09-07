#ifndef STORAGE_NV_JOURNAL_H
#define STORAGE_NV_JOURNAL_H
#include <stddef.h>
int nv_journal_init(void);
int nv_journal_append(const void *blob, size_t len);
int nv_journal_read(unsigned index, void *blob, size_t maxlen);
#endif
