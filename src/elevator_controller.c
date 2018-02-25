#include "elevator_controller.h"
#include <stdio.h>
#include "fsm.h"
#include "elevator_driver.h"
#include "floor_driver.h"
#include "order_queue.h"

///Current running state
fsm_state_e current_state;
///Next desired state
fsm_state_e next_state;
///Last visited floor
int last_floor = -1;

///Contains all state functions and transition functions
fsm_state_func state_table[FSM_NUM_STATES][FSM_NUM_STATES] = 
{
//        MOVING_UP                   MOVING_DOWN                      EMERGENCY                    EXECUTE_QUEUE             AT_FLOOR
    { state_moving_up_do   ,    state_moving_down_entry,          state_emergency_entry,              NULL,             state_at_floor_entry }, //MOVING UP
    { state_moving_up_entry,    state_moving_down_do   ,          state_emergency_entry,              NULL,             state_at_floor_entry }, //MOVING DOWN
    { state_moving_up_entry,    state_moving_down_entry,          state_emergency_do   ,              NULL,             state_at_floor_entry }, //EMERGENCY
    { state_moving_up_entry,    state_moving_down_entry,          state_emergency_entry,              NULL,             state_at_floor_entry }, //EXECUTE_QUEUE
    { state_moving_up_entry,    state_moving_down_entry,          state_emergency_entry,              NULL,             state_at_floor_do    }  //AT FLOOR
};

void elevator_controller_loop_once() {
    state_data_t state_data;
    
    state_data.motor_direction = get_motor_direction();
    state_data.motor_running = is_motor_running();
    state_data.emergency_button_status = is_emergency_button_pressed();
    state_data.current_floor = get_current_floor();
    if(state_data.current_floor != -1) {
        last_floor = state_data.current_floor;
    }
    state_data.target_floor = get_next_order(last_floor, state_data.motor_direction);


    ///Get next state function
    fsm_state_func func = state_table[current_state][next_state];
    current_state = next_state;
    if(func != NULL) {
        ///Run current state
        next_state = func(&state_data);
    }
}

void emergency_stop() {
    next_state = STATE_EMERGENCY;
}


