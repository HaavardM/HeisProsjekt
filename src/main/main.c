#include <stdio.h>
#include "elevator_controller.h"
#include "elev.h"

int main() {
    // Initialize hardware
    if (!elev_init()) {
        printf("Unable to initialize elevator hardware!\n");
        return 1;
    }

    while (1) {
        elevator_controller_loop_once();
    }

    return 0;
}
