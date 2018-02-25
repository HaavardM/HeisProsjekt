//
// Created by Emma Horn Buøen on 13.02.2018.
//
#include <elevator_driver.h>
#include "elev.h"
#include <stdbool.h>
#include <stdio.h>
#include "order_queue.h"

#define NUM_FLOORS 4

bool elevator_lights[NUM_FLOORS] = { false, false, false, false};

motor_direction_e current_motor_direction = MOTOR_DIRECTION_UP;
motor_running_e motor_running_status = MOTOR_NOT_RUNNING;

void start_motor(void) {
    motor_running_status = MOTOR_RUNNING;
    if (current_motor_direction == MOTOR_DIRECTION_UP) {
        elev_set_motor_direction(DIRN_UP);
    } else {
        elev_set_motor_direction(DIRN_DOWN);
    }

}


void stop_motor(void) {
    elev_set_motor_direction(DIRN_STOP);
    motor_running_status = MOTOR_NOT_RUNNING;
}


motor_direction_e get_motor_direction(void) {
    return current_motor_direction;
}


void set_motor_direction(motor_direction_e dir) {
    current_motor_direction = dir;
    if (motor_running_status) {
        start_motor();
    }else {
        stop_motor();
    }
}


motor_running_e is_motor_running(void) {
    return motor_running_status;
}


emergency_button_status_e is_emergency_button_pressed(void) {
    if (elev_get_stop_signal() == 0) {
        elev_set_stop_lamp(0);
        return EMERGENCY_NOT_PRESSED;
    }else {
        elev_set_stop_lamp(1);
        return EMERGENCY_PRESSED;
    }
}


void clear_elevator_light(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor\n");
        return;
    }
    elev_set_button_lamp(BUTTON_COMMAND, floor, 0);
    elevator_lights[floor] = false;
}
void set_elevator_light(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor\n");
        return;
    }
    elev_set_button_lamp(BUTTON_COMMAND, floor,1);
    elevator_lights[floor] = true;
}
void update_elevator_driver(void) {
    for(int i = 0; i < NUM_FLOORS; i++) {
        if (elev_get_button_signal(BUTTON_COMMAND, i) == 1) {
            set_elevator_light(i);
            if(!elevator_lights[i]) {
                add_to_order_queue_dest(i);
            }
        }
    }


}

