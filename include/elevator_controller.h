#ifndef ELEVATOR_CONTROLLER_H
#define ELEVATOR_CONTROLLER_H

#include "fsm.h"

///Run emergency stop
void emergency_stop();

///Run current elevator state once
void elevator_controller_loop_once(const state_data_s* state_data);


#endif
