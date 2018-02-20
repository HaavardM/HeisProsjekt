#include "elevator_controller.h"
#include <stdio.h>
#include "fsm.h"

///Current running state
fsm_state_e current_state;
///Next desired state
fsm_state_e next_state;

///Contains all state functions and transition functions
fsm_state_func state_table[FSM_NUM_STATES][FSM_NUM_STATES] = 
{
//        MOVING_UP          MOVING_DOWN      EMERGENCY         EXECUTE_QUEUE     AT_FLOOR
    { state_moving_up_do   ,    NULL,          NULL,              NULL,             NULL }, //MOVING UP
    { state_moving_up_entry,    NULL,          NULL,              NULL,             NULL }, //MOVING DOWN
    { state_moving_up_entry,    NULL,          NULL,              NULL,             NULL }, //EMERGENCY
    { state_moving_up_entry,    NULL,          NULL,              NULL,             NULL }, //EXECUTE_QUEUE
    { state_moving_up_entry,    NULL,          NULL,              NULL,             NULL }  //AT FLOOR
};

void elevator_controller_loop_once(const state_data_t* state_data) {
    ///Get next state function
    fsm_state_func func = state_table[current_state][next_state];
    current_state = next_state;
    if(func != NULL) {
        ///Run current state
        next_state = func(state_data);
    }
}

void emergency_stop() {
    next_state = STATE_EMERGENCY;
}


