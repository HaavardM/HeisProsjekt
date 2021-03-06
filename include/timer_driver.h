#ifndef TIMER_DRIVER_H
#define TIMER_DRIVER_H
#include <time.h>
#include <stdbool.h>

///Timer struct
typedef struct { 
    clock_t start_time;
    clock_t duration_ms;
} timer_t;


/**Create timer
 * @param d_ms Timer duration in milliseconds
 * @return Timer struct
 */
timer_t create_ms_timer(unsigned int d_ms);
/**Check if timer has elapsed
 * @param timer Timer to check
 * @return Has timer elapsed or not
 */
bool timer_has_elapsed(timer_t timer);


#endif
