#include <stdio.h>
#include "unity.h"
#include "elevator_controller_test.h"
#include "fsm.h"


void test_sampletest(void) {
    TEST_ASSERT_EQUAL_INT(2, 2);
    TEST_ASSERT_EQUAL_INT(2, 2);
}

void test_to_moving_up_transitions(void) {
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_UP][STATE_MOVING_UP], state_moving_up_do);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_DOWN][STATE_MOVING_UP], state_moving_up_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EMERGENCY][STATE_MOVING_UP], state_moving_up_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_AT_FLOOR][STATE_MOVING_UP], state_moving_up_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EXECUTE_QUEUE][STATE_MOVING_UP], state_moving_up_entry);
}
void test_to_moving_down_transitions(void) {
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_DOWN][STATE_MOVING_DOWN], state_moving_down_do);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EMERGENCY][STATE_MOVING_DOWN], state_moving_down_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EXECUTE_QUEUE][STATE_MOVING_DOWN], state_moving_down_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_AT_FLOOR][STATE_MOVING_DOWN], state_moving_down_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_UP][STATE_MOVING_DOWN], state_moving_down_entry);
}


int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sampletest);
    RUN_TEST(test_to_moving_up_transitions);
    return UNITY_END();
}
