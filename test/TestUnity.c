#include <stdio.h>
#include "unity.h"
#include "elevator_controller_test.h"
#include "fsm.h"
#include "order_queue.h"


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

void test_to_emergency_transitions(void) {
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EMERGENCY][STATE_EMERGENCY], state_emergency_do);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_DOWN][STATE_EMERGENCY], state_emergency_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_MOVING_UP][STATE_EMERGENCY], state_emergency_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_AT_FLOOR][STATE_EMERGENCY], state_emergency_entry);
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EXECUTE_QUEUE][STATE_EMERGENCY], state_emergency_entry);
}

void test_execute_queue_transitions(void) {
    TEST_ASSERT_EQUAL_INT(state_table[STATE_EXECUTE_QUEUE][STATE_EXECUTE_QUEUE], state_execute_queue_do);
    for(int i = 0; i < FSM_NUM_STATES; ++i) {
        if(i == STATE_EXECUTE_QUEUE) continue;
        TEST_ASSERT_EQUAL_INT(state_table[i][STATE_EXECUTE_QUEUE], state_execute_queue_entry);
    }
}

void test_order_queue(void) {
    add_to_order_queue_up(3);
    add_to_order_queue_down(1);
    TEST_ASSERT_EQUAL_INT(3, get_next_order(2, MOTOR_DIRECTION_UP));
    TEST_ASSERT_EQUAL_INT(1, get_next_order(2, MOTOR_DIRECTION_DOWN));
    empty_queue();
    TEST_ASSERT_EQUAL_INT(-1, get_next_order(2, MOTOR_DIRECTION_UP));
    TEST_ASSERT_EQUAL_INT(-1, get_next_order(2, MOTOR_DIRECTION_DOWN));
    add_to_order_queue_up(2);
    add_to_order_queue_up(3);
    TEST_ASSERT_EQUAL_INT(2, get_next_order(1, MOTOR_DIRECTION_UP));
    TEST_ASSERT_EQUAL_INT(2, get_next_order(1, MOTOR_DIRECTION_DOWN));
    empty_queue();
    add_to_order_queue_up(1);
    TEST_ASSERT_EQUAL_INT(1, get_next_order(2, MOTOR_DIRECTION_UP));
}


int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sampletest);
    RUN_TEST(test_to_moving_up_transitions);
    RUN_TEST(test_to_state_at_floor);
    RUN_TEST(test_to_moving_down_transitions);
    RUN_TEST(test_order_queue);
    RUN_TEST(test_to_emergency_transitions);
    RUN_TEST(test_execute_queue_transitions);
    return UNITY_END();
}
