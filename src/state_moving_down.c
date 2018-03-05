//
// Created by Emma Horn Buøen on 20.02.2018.
//

#include <fsm.h>
#include "elevator_driver.h"
#include "door_driver.h"
#include "fsm.h"
#include <stdio.h>

#define INVALID_FLOOR -1

fsm_state_e state_moving_down_entry(const state_data_t* state_data_p)  {
    printf("State moving down entry\n");
    set_motor_direction(MOTOR_DIRECTION_DOWN);
    start_motor();
    return STATE_MOVING_DOWN;

}
fsm_state_e state_moving_down_do(const state_data_t* state_data_p) {
    if (state_data_p ->current_floor == state_data_p ->target_floor && state_data_p->target_floor != INVALID_FLOOR) {
        //If at target floor, stop
        return STATE_AT_FLOOR;
    } else if(state_data_p->last_floor == INVALID_FLOOR && state_data_p->current_floor != INVALID_FLOOR) { 
        //If no target floor, stop
        return STATE_AT_FLOOR;
    } else if(state_data_p->current_floor < state_data_p->target_floor && state_data_p->current_floor != INVALID_FLOOR) {
        //If going the wrong way, switch direction
        return STATE_MOVING_UP;
    } else {
        //Else continue
        return STATE_MOVING_DOWN;
    }

}
