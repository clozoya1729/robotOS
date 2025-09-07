#include "app_modes.h"
static app_mode_t g_mode = MODE_BOOT;
void modes_init(void){ g_mode = MODE_IDLE; }
void modes_set(app_mode_t m){ g_mode = m; }
app_mode_t modes_get(void){ return g_mode; }
