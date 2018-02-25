//
// Created by Emma Horn Buøen on 25.02.2018.
//
#include <fsm.h>
#include "order_queue.h"



fsm_state_e state_emergency_entry(const state_data_t* state_data_p) {
    stop_motor();
    empty_queue();
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