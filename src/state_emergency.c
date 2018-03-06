#include <fsm.h>
#include "order_queue.h"
#include <stdio.h>
#include "floor_driver.h"
#include "elevator_driver.h"
#include "door_driver.h"

#define NUM_FLOORS 4
#define INVALID_FLOOR -1

fsm_state_e state_emergency_entry(const state_data_t* state_data_p) {
    printf("State emergency entry\n");
    stop_motor();
    return STATE_EMERGENCY;
}

fsm_state_e state_emergency_do(const state_data_t* state_data_p) {
    //Clear queue
    empty_queue();
    //Clear lights
    for(int i = 0; i < NUM_FLOORS; ++i) {
        clear_elevator_light(i);
        clear_floor_light(i);
    }
    //If we're at a floor, open the doors
    if(state_data_p->current_floor != INVALID_FLOOR) {
        open_door();
    } else {
        //If not, close
        close_door();
    }
    
    if (state_data_p->emergency_button_pressed) {
        return STATE_EMERGENCY;
    } else if (state_data_p->current_floor == INVALID_FLOOR) {
        return STATE_EXECUTE_QUEUE;
    }
    return STATE_AT_FLOOR;
}
