//
// Created by Emma Horn Buøen on 13.02.2018.
//
#include <elevator_driver.h>
#include "elev.h"

motor_direction_e current_motor_direction = MOTOR_DIRECTION_UP;
motor_running_e motor_running_status = MOTOR_NOT_RUNNING;

void start_motor(void) {
    elev_set_motor_direction(get_motor_direction());
    motor_running_status = MOTOR_RUNNING;
}


void stop_motor(void) {
    elev_set_motor_direction(0);
    motor_running_status = MOTOR_NOT_RUNNING;
}


motor_direction_e get_motor_direction(void) {
    return current_motor_direction;
}


void set_motor_direction(motor_direction_e dir) {
    current_motor_direction = dir;
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
    elev_set_button_lamp(BUTTON_COMMAND, floor-1, 0);
}
void set_elevator_light(int floor) {
    elev_set_button_lamp(BUTTON_COMMAND, floor-1,1);
}
void update_floor_driver(int floor) {
    if (elev_get_button_signal(BUTTON_COMMAND, floor) == 1) {
        set_elevator_light(floor);
    } else {
        clear_elevator_light(floor);
    }

}

