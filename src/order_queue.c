//
// Created by Emma Horn Buøen on 20.02.2018.
//
#include "order_queue.h"
#include <stdio.h>

typedef enum {NO_ORDER = 0, ORDER = 1} has_order_e;

#define NUM_FLOORS 4

int orders_up[NUM_FLOORS] = { 0, 0, 0, 0};
int orders_down[NUM_FLOORS] = { 0, 0, 0, 0};
int orders_destination[NUM_FLOORS] = { 0, 0, 0, 0 };


void add_to_order_queue_up(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i", floor);
        return;
    }
    
    orders_up[floor] = ORDER;
}
void add_to_order_queue_down(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i", floor);
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
        fprintf(stderr, "Invalid floor id %i", current_floor);
        return -1;
    }
    //Which direction to look
    int increment = (dir == MOTOR_DIRECTION_UP) ? 1 : -1;
    //Get pointer to active queue
    int* queue = (dir == MOTOR_DIRECTION_UP) ? orders_up : orders_down;
    //Check current floor and up
    for(int i = current_floor; i < NUM_FLOORS && i >= 0; i += increment) {
        if(queue[i] == ORDER || orders_destination[i] == ORDER) return i;
    }
    //Finn start index etter første iterasjon
    //Finn retning og queue etter første iterasjon
    //Itterer gjennom andre queue
    //Snu retning, bytt queue og iterer gjennom første del av queue nummer 1
    
    return -1;
}
void add_to_order_queue_dest(int floor) {
    if(floor < 0 || floor >= NUM_FLOORS) {
        fprintf(stderr, "Invalid floor id %i", floor);
        return;
    }
    orders_destination[floor] = ORDER;
}
