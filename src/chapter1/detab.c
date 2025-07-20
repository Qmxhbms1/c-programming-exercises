#include <stdio.h>
#define TAB_WIDTH 8

int main(void) {
  int i, character, current_column_number;
  current_column_number = 0;
  while((character = getchar()) != EOF) {
    if (character == '\n') {
      putchar('\n');
      current_column_number = 0;
    }
    else if (character == '\t') {
      for(i = (current_column_number % TAB_WIDTH); i < TAB_WIDTH; i++) {
        putchar(' ');
      }
      current_column_number = 0;
    } else {
      putchar(character);
      ++current_column_number;
    }
  }

  return 0;
}
