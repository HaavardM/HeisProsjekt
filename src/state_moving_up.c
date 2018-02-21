//
// Created by Emma Horn Buøen on 20.02.2018.
//

#include <fsm.h>
#include "elevator_driver.h"
#include "door_driver.h"
#include "fsm.h"

fsm_state_e state_moving_up_entry(const state_data_t* state_data_p)  {
    close_door();
    set_motor_direction(MOTOR_DIRECTION_UP);
    start_motor();
    return STATE_MOVING_UP;

}
fsm_state_e state_moving_up_do(const state_data_t* state_data_p) {
    if (state_data_p ->current_floor == state_data_p ->target_floor) {
        return STATE_AT_FLOOR;
    }else {
        return STATE_MOVING_UP;
    }

}
