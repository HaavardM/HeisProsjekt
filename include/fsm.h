#ifndef FSM_H
#define FSM_H
#include "motor_defines.h"
#include "stdbool.h"

///FSM states enum
typedef enum {STATE_MOVING_UP, STATE_MOVING_DOWN, STATE_EMERGENCY, STATE_EXECUTE_QUEUE, STATE_AT_FLOOR, FSM_NUM_STATES} fsm_state_e;

///Struct to be passed in, containing useful data
typedef struct {
    //Fill inn neccesary data here
    motor_direction_e motor_direction;
    motor_running_e motor_running;
    bool emergency_button_pressed;
    int target_floor;
    int current_floor;
    int last_floor;
} state_data_t;

///FSM state function pointer type
typedef fsm_state_e (* const fsm_state_func)(const state_data_t*);


///States
/************************************/
/// At floor
fsm_state_e state_at_floor_entry(const state_data_t* state_data_p);
fsm_state_e state_at_floor_do(const state_data_t* state_data_p);

/// State Moving UP:
fsm_state_e state_moving_up_entry(const state_data_t* state_data_p);
fsm_state_e state_moving_up_do(const state_data_t* state_data_p);

/// State Moving DOWN:
fsm_state_e state_moving_down_entry(const state_data_t* state_data_p);
fsm_state_e state_moving_down_do(const state_data_t* state_data_p);

/// State Emergency
fsm_state_e state_emergency_entry(const state_data_t* state_data_p);
fsm_state_e state_emergency_do(const state_data_t* state_data_p);

/// Stat execute queue
fsm_state_e state_execute_queue_entry(const state_data_t* state_data_p);
fsm_state_e state_execute_queue_do(const state_data_t* state_data_p);
#endif
