#include "fsm.h"
#include "elevator_driver.h"
#include "door_driver.h"

fsm_state_e state_at_floor_entry(const state_data_s* state_data_p) {
   stop_motor();
   open_door();
   //TODO Start timer when ready
   return STATE_AT_FLOOR; 
}   

fsm_state_e state_at_floor_do(const state_data_s* state_data_p) {
    int timer_elapsed = 0;
    if(timer_elapsed) {
        return STATE_EXECUTE_QUEUE;
    }
    return STATE_AT_FLOOR;
}


