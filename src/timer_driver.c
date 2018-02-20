#include "timer_driver.h"

timer_s create_timer(unsigned int d_ms) {
    timer_s temp;
    temp.duration_ms = d_ms;
    temp.start_time = clock(); 
    return temp;
}

bool timer_has_elapsed(timer_s timer) {
    clock_t now = clock();
    long elapsed = (((double)(now - timer.start_time)) / CLOCKS_PER_SEC) * 1000;
    return elapsed > timer.duration_ms;
}
