#ifndef FSM_H
#define FSM_H
#include "elevator_driver.h"

///FSM states enum
typedef enum {STATE_MOVING_UP, STATE_MOVING_DOWN, STATE_EMERGENCY, STATE_EXECUTE_QUEUE, STATE_AT_FLOOR, FSM_NUM_STATES} fsm_state_e;

///Struct to be passed in, containing useful data
typedef struct {
    //Fill inn neccesary data here
    motor_direction_e motor_direction;
    motor_running_e motor_running;
    const emergency_button_status_e emergency_button_status;
    int target_floor; 
} state_data_s;

///FSM state function pointer type
typedef fsm_state_e (* const fsm_state_func)(const state_data_s*);


///States
/************************************/
fsm_state_e state_at_floor_entry(const state_data_s* state_data_p);
fsm_states_e state_at_floor_do(const state_data_s* state_data_p);

#endif
