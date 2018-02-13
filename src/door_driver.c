//
// Created by Emma Horn Buøen on 13.02.2018.
//

#include "elev.h"

int door_light;

int is_door_open(void){
    return door_light;
}


void open_door(void){
    elev_set_door_open_lamp(1);
    door_light = 1;
}

void close_door(void) {
    elev_set_door_open_lamp(0);
    door_light = 0;
}




