#include "fsm.h"
#include "order_queue.h"
#include <stdio.h>


fsm_state_e state_execute_queue_entry(const state_data_t* state_data_p) {
    printf("State execute queue entry\n");
    return STATE_EXECUTE_QUEUE;
}

fsm_state_e state_execute_queue_do(const state_data_t* state_data_p) {
    if(state_data_p->last_floor == -1) {
        return STATE_MOVING_UP;
    }
    if(state_data_p->target_floor == -1) {
        return STATE_EXECUTE_QUEUE;
    } else if(state_data_p->target_floor > state_data_p->last_floor) {
        return STATE_MOVING_UP;
    } else if(state_data_p->target_floor < state_data_p->last_floor) {
        return STATE_MOVING_DOWN;
    } else {
        fprintf(stderr, "Order to current floor?\n");
        return STATE_AT_FLOOR;
    }
}
