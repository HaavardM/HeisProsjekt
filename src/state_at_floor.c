#include "fsm.h"
#include "elevator_driver.h"
#include "floor_driver.h"
#include "door_driver.h"
#include "timer_driver.h"
#include <stdbool.h>
#include <stdio.h>
#include "order_queue.h"

#define INVALID_VALUE -1

timer_t current_timer;

fsm_state_e state_at_floor_entry(const state_data_t* state_data_p) {
    printf("State at floor entry\n");
    
    stop_motor();
    open_door();
    //3 second timer
    current_timer = create_timer(3 * 1000);
    return STATE_AT_FLOOR; 
}   

fsm_state_e state_at_floor_do(const state_data_t* state_data_p) {
    
    if(state_data_p->current_floor == INVALID_VALUE) {
        //In between floors!
        fprintf(stderr, "Invalid floor\n");
        return STATE_EXECUTE_QUEUE;
    }
    
    //Clear lights at floor
    clear_elevator_light(state_data_p->current_floor);
    clear_floor_light(state_data_p->current_floor);

    //Wait for timer
    bool timer_elapsed = timer_has_elapsed(current_timer);
    if(timer_elapsed) {
        clear_order_in_queue(state_data_p->current_floor);
        return STATE_EXECUTE_QUEUE;
    }
    return STATE_AT_FLOOR;
}


