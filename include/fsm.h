#ifndef FSM_H
#define FSM_H

///FSM states enum
typedef enum {STATE_MOVING_UP, STATE_MOVING_DOWN, STATE_EMERGENCY, STATE_EXECUTE_QUEUE, STATE_AT_FLOOR, FSM_NUM_STATES} fsm_state_e;

///Struct to be passed in, containing useful data
typedef struct {
    //Fill inn neccesary data here
} state_data_s;

///FSM state function pointer type
typedef fsm_state_e (*fsm_state_func)(state_data_s);


#endif
