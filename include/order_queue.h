#ifndef HEISPROSJEKT_ORDER_QUEUE_H
#define HEISPROSJEKT_ORDER_QUEUE_H
#include "motor_defines.h"

/** Add up order from floor
 *  @param floor - Which floor ordered from
 */
void add_to_order_queue_up(int floor);

/** Add down order from floor
 * @param floor - Which floor ordered from
 */
void add_to_order_queue_down(int floor);

///Empty all queues
void empty_queue(void);

/** Get next order from queues
 * @param current_floor
 * @param dir motor direction
 * @return next floor to stop, -1 if no orders in queue
 */
int get_next_order(int current_floor, motor_direction_e dir);

/** Add down order from floor
 * @param floor - Which floor ordered from
 */
void add_to_order_queue_dest(int floor);

/** Clear all orders from given floor
 * @param floor Floor to clear
 */
void clear_order_in_queue(int floor);


#endif //HEISPROSJEKT_ORDER_QUEUE_H
