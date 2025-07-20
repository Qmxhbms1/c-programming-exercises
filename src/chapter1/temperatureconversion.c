#include <stdio.h>
#define LOWER 0.0f
#define UPPER 300.0f
#define STEP 20.0f

float fahrenheit_to_celsius(float fahrenheit) {
  return (5.0/9.0) * (fahrenheit - 32.0);
}

float celsius_to_fahrenheit(float celsius) {
  return ((9.0/5.0) * celsius) + 32.0; 
}

void print_increasing(float lower, float upper, float step, float (*converter)(float)) {
  for (float temperature = upper; temperature >= lower; temperature -= step)
    printf("%3.0f %6.1f\n", temperature, converter(temperature));
}

void print_decreasing(float lower, float upper, float step, float (*converter)(float)) {
  for (float temperature = lower; temperature <= upper; temperature += step)
    printf("%3.0f %6.1f\n", temperature, converter(temperature));
}

int main(void) {
  printf("Fah    Cel\n");
  print_increasing(LOWER, UPPER, STEP, fahrenheit_to_celsius);
  printf("Cel    Fah\n");
  print_increasing(LOWER, UPPER, STEP, celsius_to_fahrenheit);
  printf("Fah    Cel\n");
  print_decreasing(LOWER, UPPER, STEP, fahrenheit_to_celsius);
  printf("Cel    Fah\n");
  print_decreasing(LOWER, UPPER, STEP, celsius_to_fahrenheit);

  return 0;
}
