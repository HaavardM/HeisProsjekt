//
// Created by Emma Horn Buøen on 20.02.2018.
//

#include <fsm.h>
#include "elevator_driver.h"
#include "door_driver.h"
#include "fsm.h"

fsm_state_e state_moving_down_entry(const state_data_s* state_data_p)  {
    close_door();
    set_motor_direction(MOTOR_DIRECTION_DOWN);
    start_motor();
    return STATE_MOVING_DOWN;

}
fsm_state_e state_moving_down_do(const state_data_s* state_data_p) {
    if (state_data_p ->current_floor == state_data_p ->target_floor) {
        return STATE_AT_FLOOR;
    }else {
        return STATE_MOVING_DOWN;
    }

}