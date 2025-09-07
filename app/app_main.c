#include "app_tasks.h"
#include "app_modes.h"
int main(void){
    modes_init();
    (void)task_fast_1ms; (void)task_med_10ms; (void)task_slow_100ms;
    return 0;
}
