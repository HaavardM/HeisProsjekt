#ifndef FSM_H
#define FSM_H
#include "motor_defines.h"
#include "stdbool.h"

///FSM states enum
typedef enum {STATE_MOVING_UP, STATE_MOVING_DOWN, STATE_EMERGENCY, STATE_EXECUTE_QUEUE, STATE_AT_FLOOR, FSM_NUM_STATES} fsm_state_e;

///Struct to be passed in, containing useful data
typedef struct {
    //Fill inn neccesary data here
    ///Current motor direction
    motor_direction_e motor_direction;
    ///Motor running state
    motor_running_e motor_running;
    ///Is emergency button pressed?
    bool emergency_button_pressed;
    ///Elevator target floor (current order)
    int target_floor;
    ///Current floor (-1 if in between floors)
    int current_floor;
    ///Last visited floor
    int last_floor;
} state_data_t;

///FSM state function pointer type
typedef fsm_state_e (* const fsm_state_func)(const state_data_t*);

#endif

