#include "floor_driver.h"
#include "elev.h"
#include "order_queue.h"
#include <stdbool.h>

bool btn_light_state[2][4] = {
    { false, false, false, false },
    { false, false, false, false }
};
void clear_floor_light(int floor) {
    btn_light_state[BUTTON_CALL_UP][floor] = 0;
    btn_light_state[BUTTON_CALL_DOWN][floor] = 0;
}

void update_floor_driver(bool init_complete) {
    //Iteratre through each floor
    for(int i = 0; i < 3; ++i) {
        int up_index = i;
        int down_index = i + 1;
        //Is button up pressed at floor i?
        bool btn_up = elev_get_button_signal(BUTTON_CALL_UP, up_index);
        //Is button down pressed at floor i?
        bool btn_down = elev_get_button_signal(BUTTON_CALL_DOWN, down_index);
        //If button is pressed and light not already set
        if(btn_up && !btn_light_state[BUTTON_CALL_UP][up_index] && init_complete) {
            //Set light
            btn_light_state[BUTTON_CALL_UP][up_index] = true;
            //Add to up queue
            add_to_order_queue_up(up_index);
        }
        if(btn_down && !btn_light_state[BUTTON_CALL_DOWN][down_index] && init_complete) {
            //Set light
            btn_light_state[BUTTON_CALL_DOWN][down_index] = 1;
            //Add to down queue
            add_to_order_queue_down(down_index);
        }
    }
    
    for(int i = 0; i < 3; ++i) {
        int up_index = i;
        int down_index = i + 1;
        //Set lights based on state
        elev_set_button_lamp(BUTTON_CALL_UP, up_index, btn_light_state[BUTTON_CALL_UP][up_index]);
        //Set light based on state
        elev_set_button_lamp(BUTTON_CALL_DOWN, down_index, btn_light_state[BUTTON_CALL_DOWN][down_index]);
    }
}
int get_current_floor(void) {
    return elev_get_floor_sensor_signal();
}
void set_floor_indicator(int floor) {
    elev_set_floor_indicator(floor);
}
