#include <stdio.h>
#include "unity.h"

void test_sampletest(void) {
    TEST_ASSERT_EQUAL_INT(2, 2);
    TEST_ASSERT_EQUAL_INT(2, 2);
}


int main(int argc, char** argv) {
    UNITY_BEGIN();
    RUN_TEST(test_sampletest);
    return UNITY_END();
}
