//
// Created by Emma Horn Buøen on 13.02.2018.
//

#ifndef HEISPROSJEKT_DOOR_DRIVER_H
#define HEISPROSJEKT_DOOR_DRIVER_H



/** Opens door
*/
void open_door(void);

/** Closes door
*/
void close_door(void);

/**Checks if door is open
 * @return 1 if door is open
 * @return 0 if door is closed
 */
int is_door_open(void);

#endif //HEISPROSJEKT_DOOR_DRIVER_H
