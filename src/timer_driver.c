#include "timer_driver.h"

timer_t create_ms_timer(unsigned int d_ms) {
    timer_t temp;
    temp.duration_ms = d_ms;
    temp.start_time = clock(); 
    return temp;
}

bool timer_has_elapsed(timer_t timer) {
    clock_t now = clock();
    long elapsed = (((double)(now - timer.start_time)) / CLOCKS_PER_SEC) * 1000;
    return elapsed > timer.duration_ms;
}
