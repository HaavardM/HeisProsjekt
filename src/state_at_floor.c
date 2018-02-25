#include "fsm.h"
#include "elevator_driver.h"
#include "door_driver.h"
#include "timer_driver.h"
#include <stdbool.h>
#include <stdio.h>

timer_t current_timer;

fsm_state_e state_at_floor_entry(const state_data_t* state_data_p) {
    printf("State at floor entry\n");
    if(state_data_p->current_floor == -1) {
        fprintf(stderr, "Invalid floor\n");
    } else {
        clear_elevator_light(state_data_p->current_floor);
    }
    stop_motor();
    open_door();
    //3 second timer
    current_timer = create_timer(3 * 1000);
    return STATE_AT_FLOOR; 
}   

fsm_state_e state_at_floor_do(const state_data_t* state_data_p) {
    //Wait for timer
    bool timer_elapsed = timer_has_elapsed(current_timer);
    if(timer_elapsed) {
        return STATE_EXECUTE_QUEUE;
    }
    return STATE_AT_FLOOR;
}


