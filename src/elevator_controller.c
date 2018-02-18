#include "elevator_controller.h"
#include <stdio.h>
#include "fsm.h"


fsm_state_e current_state;
fsm_state_e next_state;

///Contains all state functions and transition functions
fsm_state_func state_table[FSM_NUM_STATES][FSM_NUM_STATES] = 
{
    {},
    {}, 
    {},
    {},
    {}
};

void elevator_controller_loop_once() {
    state_data_s data;
    fsm_state_func func = state_table[current_state][next_state];
    current_state = next_state;
    if(func != NULL) {
        next_state = func(data);
    }
}

void emergency_stop() {

}


