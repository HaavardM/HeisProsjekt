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
    {NULL, NULL, NULL, NULL, state_at_floor_entry},
    {NULL, NULL, NULL, NULL, state_at_floor_entry}, 
    {NULL, NULL, NULL, NULL, state_at_floor_entry},
    {NULL, NULL, NULL, NULL, state_at_floor_entry},
    {NULL, NULL, NULL, NULL, state_at_floor_do}
};

void elevator_controller_loop_once(const state_data_s* state_data) {
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


