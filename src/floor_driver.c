#include "floor_driver.h"
#include "elev.h"
int btn_light_state[2][4] = {
    { 0, 0, 0, 0},
    { 0, 0, 0, 0}
};
void clear_floor_light(int floor) {
    btn_light_state[BUTTON_CALL_UP][floor] = 0;
    btn_light_state[BUTTON_CALL_DOWN][floor] = 0;
}

void update_floor_driver() {
    //Iteratre through each floor
    for(int i = 0; i < 3; ++i) {
        int up_index = i;
        int down_index = i + 1;
        //Is button up pressed at floor i?
        int btn_up = elev_get_button_signal(BUTTON_CALL_UP, up_index);
        //Is button down pressed at floor i?
        int btn_down = elev_get_button_signal(BUTTON_CALL_DOWN, down_index);
        //If button is pressed and light not already set
        if(btn_up && !btn_light_state[BUTTON_CALL_UP][up_index]) {
            //Set light
            btn_light_state[BUTTON_CALL_UP][up_index] = 1;
            //TODO Add to up queue
        }
        if(btn_down && !btn_light_state[BUTTON_CALL_DOWN][down_index]) {
            //Set light
            btn_light_state[BUTTON_CALL_DOWN][down_index] = 1;
            //TODO Add to down queue
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
