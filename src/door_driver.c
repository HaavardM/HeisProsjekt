//
// Created by Emma Horn Buøen on 13.02.2018.
//

#include <door_driver.h>
#include "elev.h"

door_state_e door_light;

door_state_e is_door_open(void){
    return door_light;
}


void open_door(void){
    elev_set_door_open_lamp(1);
    door_light = DOOR_OPEN;
}

void close_door(void) {
    elev_set_door_open_lamp(0);
    door_light = DOOR_CLOSED;
}




