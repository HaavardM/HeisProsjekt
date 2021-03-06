#ifndef FLOOR_DRIVER_H
#define FLOOR_DRIVER_H
#include <stdbool.h>

/** Clear light at floor
 * @param floor Which floor light to clear
 */ 
void clear_floor_light(int floor);

/** Floor driver main function
 * @param init_complete Init is completed
 */
void update_floor_driver(bool init_complete);

/** Check if elevator is at a floor
 * @return current floor if at a floor, -1 if between floors
 */
int get_current_floor(void);

/// @param desired floor
void set_floor_indicator(int floor);


#endif
