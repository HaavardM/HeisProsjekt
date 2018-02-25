#include "fsm.h"
#include "order_queue.h"
#include <stdio.h>

fsm_state_e state_execute_queue_do(const state_data_t* state_data_p) {
    if(state_data_p->last_floor == -1) {
        return STATE_MOVING_UP;
    }
    if(state_data_p->target_floor == -1) {
        if(state_data_p->current_floor == -1) {
            add_to_order_queue_dest(state_data_p->last_floor);
        }
        return STATE_EXECUTE_QUEUE;
    } else if(state_data_p->target_floor > state_data_p->last_floor) {
        return STATE_MOVING_UP;
    } else if(state_data_p->target_floor < state_data_p->last_floor) {
        return STATE_MOVING_DOWN;
    } else {
        fprintf(stderr, "Order to current floor?");
        return STATE_AT_FLOOR;
    }
}
