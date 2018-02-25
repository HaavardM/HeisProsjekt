//
// Created by Emma Horn Buøen on 25.02.2018.
//
#include <fsm.h>
#include "order_queue.h"
#include <stdio.h>
#include "floor_driver.h"
#include "elevator_driver.h"

#define NUM_FLOORS 4

fsm_state_e state_emergency_entry(const state_data_t* state_data_p) {
    printf("State emergency entry\n");
    stop_motor();
    empty_queue();
    for(int i = 0; i < NUM_FLOORS; ++i) {
        clear_elevator_light(i);
        clear_floor_light(i);
    }
    return STATE_EMERGENCY;
}

fsm_state_e state_emergency_do(const state_data_t* state_data_p) {
    if (state_data_p ->emergency_button_status == 1) {
        empty_queue();
        return STATE_EMERGENCY;
    }
    if (state_data_p->current_floor == -1) {
        return STATE_EXECUTE_QUEUE;
    }else {
        return STATE_AT_FLOOR;
    }
}
