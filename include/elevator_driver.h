//
// Created by Emma Horn Buøen on 13.02.2018.
//

#ifndef HEISPROSJEKT_ELEVATOR_DRIVER_H
#define HEISPROSJEKT_ELEVATOR_DRIVER_H

typedef enum {MOTOR_DIRECTION_DOWN = 0, MOTOR_DIRECTION_UP = 1} motor_direction_e;
typedef enum {MOTOR_NOT_RUNNING = 0, MOTOR_RUNNING = 1} motor_running_e;
typedef enum {EMERGENCY_NOT_PRESSED = 0, EMERGENCY_PRESSED = 1} emergency_button_status_e;
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
emergency_button_status_e is_emergency_button_pressed(void);
/**
 * Clears the elevator light of the desired floor
 * @param floor is the desired floor
 */
void clear_elevator_light(int floor);

/**
 * Updates the module
 */
void update_floor_driver(void);

#endif //HEISPROSJEKT_ELEVATOR_DRIVER_H
