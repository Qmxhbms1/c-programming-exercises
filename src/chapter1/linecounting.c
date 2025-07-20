#include <stdio.h>

int main(void) {
  int character;
  int newline_counter, tab_counter, blank_counter;
  newline_counter = tab_counter = blank_counter = 0;
  while ((character = getchar()) != EOF)  {
    if (character == ' ') ++blank_counter;
    else if (character == '\n') ++newline_counter;
    else if (character == '\t') ++tab_counter;
  }
  int total = blank_counter + tab_counter + newline_counter;
  printf("%d %d %d %d\n", blank_counter, tab_counter, newline_counter, total);
  return 0;
}
