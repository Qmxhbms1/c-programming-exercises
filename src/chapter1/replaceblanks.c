#include <stdio.h>

int is_space(int character) {
  return character == ' ';
}

void print_character(int character) {
  switch (character) {
    case '\t': printf("\\t"); break;
    case '\b': printf("\\b"); break;
    case '\\': printf("\\\\"); break;
    default: putchar(character); break;
  }
}

void test_character(int character, int *last_was_space) {
  if (is_space(character) && *last_was_space) {
    return;
  }
  print_character(character);
}

int main(void) {
  int character;
  int last_was_space = 0;

  while ((character = getchar()) != EOF) {
    test_character(character, &last_was_space);
 }

  return 0;
}
