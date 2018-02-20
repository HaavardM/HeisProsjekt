//
// Created by Emma Horn Buøen on 20.02.2018.
//

#ifndef HEISPROSJEKT_ORDER_QUEUE_H
#define HEISPROSJEKT_ORDER_QUEUE_H



void add_to_order_queue_up(int floor);
void add_to_order_queue_down(int floor);
void empty_queue(void);
int get_next_order(int cuurent_floor, int dir);
void add_to_order_queue_dest(int floor);


#endif //HEISPROSJEKT_ORDER_QUEUE_H
