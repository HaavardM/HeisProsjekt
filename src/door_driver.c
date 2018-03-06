#include <door_driver.h>
#include "elev.h"

door_state_e door_state;

door_state_e is_door_open(void){
    return door_state;
}


void open_door(void){
    elev_set_door_open_lamp(1);
    door_state = DOOR_OPEN;
}

void close_door(void) {
    elev_set_door_open_lamp(0);
    door_state = DOOR_CLOSED;
}




