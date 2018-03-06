#ifndef HEISPROSJEKT_ELEVATOR_DRIVER_H
#define HEISPROSJEKT_ELEVATOR_DRIVER_H
#include "motor_defines.h"
#include "stdbool.h"
/**
 * Starts motor
 */
void start_motor(void);

/**
 * Stops motor
 */
void stop_motor(void);

/**
 * Returns motor direction
 * @return MOTOR_DIRECTION_UP if direction is up
 * @return MOTOR_DIRECTION_DOWN if direction is down
 */
motor_direction_e get_motor_direction(void);

/**
 * Set motor direction
 * @param dir is the desired direction of the motor
 */
void set_motor_direction(motor_direction_e dir);

/**
 * Checks if the elevator is moving
 * @return MOTOR_RUNNING if elevator is moving
 * @return MOTOR_NOT_RUNNING if elevator is still
 */
motor_running_e is_motor_running(void);

/**
 * Checks if the emeregency button is pressed
 * @return EMERGENCY_NOT_PRESSED if button is not pressed
 * @return EMERGENCY_PRESSED if button is pressed
 */
bool is_emergency_button_pressed(void);
/**
 * Clears the elevator light of the desired floor
 * @param floor is the desired floor
 */
void clear_elevator_light(int floor);

/** Updates the module
 * @param init_complete Init is completed
 */
void update_elevator_driver(bool init_complete);

#endif //HEISPROSJEKT_ELEVATOR_DRIVER_H
