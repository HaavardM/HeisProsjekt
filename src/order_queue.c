//
// Created by Emma Horn Buøen on 20.02.2018.
//
#include "order_queue.h"
#include <stdio.h>

typedef enum {NO_ORDER = 0, ORDER = 1} has_order_e;

#define NUM_FLOORS 4

has_order_e orders_up[NUM_FLOORS] = { 0, 0, 0, 0};
has_order_e orders_down[NUM_FLOORS] = { 0, 0, 0, 0};
has_order_e orders_destination[NUM_FLOORS] = { 0, 0, 0, 0 };


void add_to_order_queue_up(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i\n", floor);
        return;
    }
    
    orders_up[floor] = ORDER;
}
void add_to_order_queue_down(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i\n", floor);
        return;
    }
    orders_down[floor] = ORDER;
}
void empty_queue(void) {
    for(int i = 0; i < NUM_FLOORS; ++i) {
        orders_down[i] = NO_ORDER;
        orders_up[i] = NO_ORDER;
        orders_destination[i] = NO_ORDER;
    }
}

int get_next_order(int current_floor, motor_direction_e dir) {
    if(current_floor < 0 || current_floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i\n", current_floor);
        return -1;
    }
    //Which direction to look
    int increment = (dir == MOTOR_DIRECTION_UP) ? 1 : -1;
    //Get pointer to active queue
    has_order_e* queue = (dir == MOTOR_DIRECTION_UP) ? orders_up : orders_down;
    //Check current floor and up
    int floor = current_floor;
    //Look in multiple directions
    for(int i = 0; i < 2; ++i) {
        //Look for orders until end of list
        for(; floor < NUM_FLOORS && floor >= 0; floor += increment) {
            if(queue[floor] || orders_destination[floor]) {
                return floor;
            }
        }
        //Remove last increment
        floor -= increment;
        queue = (queue == orders_up) ? orders_down : orders_up;
        //Reverse direction
        increment *= -1;
    }
    //Loop through the remaining part of the queue
    for(; floor != current_floor && floor >= 0 && floor < NUM_FLOORS; floor += increment) {
        if(queue[floor] || orders_destination[floor]) {
            printf("Second");
            return floor;
        }
    }
    return -1;
}

void clear_order_in_queue(int floor) {
    if(floor < NUM_FLOORS || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor\n");
        return;
    }
    orders_up[floor] = NO_ORDER;
    orders_down[floor] = NO_ORDER;
    orders_destination[floor] = NO_ORDER;
    
}
void add_to_order_queue_dest(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i", floor);
        return;
    }
    orders_destination[floor] = ORDER;
}
