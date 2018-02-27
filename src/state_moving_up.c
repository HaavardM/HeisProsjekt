//
// Created by Emma Horn Buøen on 20.02.2018.
//

#include <fsm.h>
#include "elevator_driver.h"
#include "door_driver.h"
#include "fsm.h"
#include <stdio.h>

fsm_state_e state_moving_up_entry(const state_data_t* state_data_p)  {
    printf("State moving up entry\n");
    set_motor_direction(MOTOR_DIRECTION_UP);
    start_motor();
    return STATE_MOVING_UP;

}
fsm_state_e state_moving_up_do(const state_data_t* state_data_p) {
    if (state_data_p ->current_floor == state_data_p ->target_floor && state_data_p->target_floor != -1) {
        //If at target floor, stop
        return STATE_AT_FLOOR;
    } if(state_data_p->target_floor == -1 && state_data_p->current_floor != -1) {
        //If no target floor, stop
        return STATE_AT_FLOOR;
    } else if(state_data_p->current_floor > state_data_p->target_floor && state_data_p->current_floor != -1) {
        //If going wrong direction, switch direction
        return STATE_MOVING_DOWN;
    } else {
        //Else continue
        return STATE_MOVING_UP;
    }

}
