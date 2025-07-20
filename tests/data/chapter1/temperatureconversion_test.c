#include <stdio.h>
#include <unity.h>

float fahrenheit_to_celsius(float fahrenheit) {
  return (5.0f/9.0f) * (fahrenheit - 32.0f);
}

void setUp(void) {}
void tearDown(void) {}

void test_fahrenheit_to_celsius_at_freezing(void) {
    TEST_ASSERT_EQUAL_FLOAT(0.0f, fahrenheit_to_celsius(32.0f));
}

void test_fahrenheit_to_celsius_at_boiling(void) {
    TEST_ASSERT_EQUAL_FLOAT(100.0f, fahrenheit_to_celsius(212.0f));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_fahrenheit_to_celsius_at_freezing);
    RUN_TEST(test_fahrenheit_to_celsius_at_boiling);
    return UNITY_END();
}
