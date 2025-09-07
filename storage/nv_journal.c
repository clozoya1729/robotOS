#include "nv_journal.h"
int nv_journal_init(void){ return 0; }
int nv_journal_append(const void *blob, size_t len){ (void)blob; (void)len; return 0; }
int nv_journal_read(unsigned index, void *blob, size_t maxlen){ (void)index; (void)blob; (void)maxlen; return 0; }
