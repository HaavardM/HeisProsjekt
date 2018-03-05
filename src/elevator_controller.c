#include "elevator_controller.h"
#include <stdio.h>
#include "elevator_driver.h"
#include "floor_driver.h"
#include "order_queue.h"
#include <stdbool.h>

//States
/****************************/
#include "state_emergency.h"
#include "state_moving_up.h"
#include "state_moving_down.h"
#include "state_execute_queue.h"
#include "state_at_floor.h"


void emergency_stop(void);

///Current running state
fsm_state_e current_state = STATE_EXECUTE_QUEUE;
///Next desired state
fsm_state_e next_state = STATE_EXECUTE_QUEUE;
///Last visited floor
int last_floor = -1;
///Init is completed
bool init_complete = false;

///Contains all state functions and transition functions
fsm_state_func state_table[FSM_NUM_STATES][FSM_NUM_STATES] = 
{
//        MOVING_UP               MOVING_DOWN               EMERGENCY            EXECUTE_QUEUE               AT_FLOOR
    { state_moving_up_do   , state_moving_down_entry, state_emergency_entry, state_execute_queue_entry, state_at_floor_entry }, //MOVING UP
    { state_moving_up_entry, state_moving_down_do   , state_emergency_entry, state_execute_queue_entry, state_at_floor_entry }, //MOVING DOWN
    { state_moving_up_entry, state_moving_down_entry, state_emergency_do   , state_execute_queue_entry, state_at_floor_entry }, //EMERGENCY
    { state_moving_up_entry, state_moving_down_entry, state_emergency_entry, state_execute_queue_do   , state_at_floor_entry }, //EXECUTE_QUEUE
    { state_moving_up_entry, state_moving_down_entry, state_emergency_entry, state_execute_queue_entry, state_at_floor_do    }  //AT FLOOR
};

void elevator_controller_loop_once() {
    //Run floor driver 
    update_floor_driver(init_complete);
    //Run elevator driver
    update_elevator_driver(init_complete);
    //Create new state data struct
    state_data_t state_data;
    //Get motor direction from elevator driver
    state_data.motor_direction = get_motor_direction();
    //Get motor running state from elevator driver
    state_data.motor_running = is_motor_running();
    //Get emergency button state from elevator driver
    state_data.emergency_button_pressed = is_emergency_button_pressed();
    //Get current floor from floor driver
    state_data.current_floor = get_current_floor();
    //Update last floor and init state if at a valid floor
    if(state_data.current_floor != -1) {
        init_complete = true;
        last_floor = state_data.current_floor;
        set_floor_indicator(last_floor);
    } 
    //Run emergency stop if pressed and not already in emergency state
    if(state_data.emergency_button_pressed && current_state != STATE_EMERGENCY && init_complete) {
        emergency_stop();
    }
    
    //Updates last floor in state struct
    state_data.last_floor = last_floor;
    //Get next order if init is completed
    if(init_complete) {
        state_data.target_floor = get_next_order(last_floor, state_data.motor_direction);
    } else {
        state_data.target_floor = -1;
    }

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


