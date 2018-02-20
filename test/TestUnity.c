#include <stdio.h>
#include "unity.h"
#include "elevator_controller_test.h"
#include "fsm.h"


void test_sampletest(void) {
    TEST_ASSERT_EQUAL_INT(2, 2);
    TEST_ASSERT_EQUAL_INT(2, 2);
}

void test_to_state_at_floor(void) {
    TEST_ASSERT_EQUAL_INT(state_table[STATE_AT_FLOOR][STATE_AT_FLOOR], state_at_floor_do);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_UP][STATE_AT_FLOOR], state_at_floor_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_DOWN][STATE_AT_FLOOR], state_at_floor_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EMERGENCY][STATE_AT_FLOOR], state_at_floor_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EXECUTE_QUEUE][STATE_AT_FLOOR], state_at_floor_entry);
}

void test_to_moving_up_transitions(void) {
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_UP][STATE_MOVING_UP], state_moving_up_do);    
}


int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sampletest);
    RUN_TEST(test_to_moving_up_transitions);
    RUN_TEST(test_to_state_at_floor);
    return UNITY_END();
}
