#include <stdio.h>
#define TAB_WIDTH 8

void print_blanks(int blank_number, int original_column_number) {
  int i, tab_count, current_column_number, final_column_number = original_column_number + blank_number;
  current_column_number = original_column_number;
  tab_count = 0;
  while(current_column_number != (((final_column_number / TAB_WIDTH) + 1) * TAB_WIDTH)) {
    current_column_number = ((current_column_number / TAB_WIDTH) + 1) * TAB_WIDTH;
    tab_count++;
  }
  for(i = 0; i < tab_count - 1; i++) {
    putchar('\t');
  }
  for(i = 0; i < (final_column_number - (1 + tab_count * TAB_WIDTH)); i++) {
    putchar(' ');
  }
}

int main(void) {
  int i, character, blank_number, current_column_number;
  blank_number = 0;
  while((character = getchar()) != EOF) {
    if (character == ' '){
      blank_number++;
      current_column_number++;
    }
    else if (character == '\t') {
      blank_number += ((current_column_number / TAB_WIDTH) + 1) - current_column_number;
      current_column_number = ((current_column_number / TAB_WIDTH) + 1) * TAB_WIDTH;
    }
    else if (character == '\n') {
      if (blank_number != 0) {
        print_blanks(blank_number, current_column_number);
      }
      blank_number = 0;
      putchar('\n');
      current_column_number = 0;
    }
    else {
      if (blank_number != 0) {
        print_blanks(blank_number, current_column_number);
      }
      blank_number = 0;
      putchar(character);
      current_column_number++;
    }
  }

  return 0;
}
