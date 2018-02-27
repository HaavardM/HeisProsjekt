#include "fsm.h"
#include "order_queue.h"
#include "door_driver.h"
#include <stdio.h>

#define INVALID_VALUE -1

fsm_state_e state_execute_queue_entry(const state_data_t* state_data_p) {
    printf("State execute queue entry\n");
    //Close door when execute queue
    close_door();
    return STATE_EXECUTE_QUEUE;
}

fsm_state_e state_execute_queue_do(const state_data_t* state_data_p) {
    if(state_data_p->last_floor == INVALID_VALUE) {
        //If the elevator hasn't visited a floor yet
        return STATE_MOVING_UP;
    }
    if(state_data_p->target_floor == INVALID_VALUE) {
        //If there are no active orders
        return STATE_EXECUTE_QUEUE;
    } else if(state_data_p->target_floor > state_data_p->last_floor) {
        //Target floor is up
        return STATE_MOVING_UP;
    } else if(state_data_p->target_floor < state_data_p->last_floor) {
        //Target floor is down
        return STATE_MOVING_DOWN;
    } else if(state_data_p->current_floor ==  state_data_p->last_floor) {
        //We're at the target floor
        fprintf(stderr, "Order to current floor?\n");
        return STATE_AT_FLOOR;
    } else if(state_data_p->current_floor == INVALID_VALUE) {
        //We're in between floors (due to anomaly or emergency)
        if(state_data_p->motor_direction == MOTOR_DIRECTION_UP) {
            //We're above last floor - go back down to last floor (target_floor == last_floor)
            return STATE_MOVING_DOWN;
        } else {
            //We're below last floor
            return STATE_MOVING_UP;
        }
    }
    
    fprintf(stderr, "Execute queue logic did not handle case correctly\n");
    return STATE_EXECUTE_QUEUE;
}
