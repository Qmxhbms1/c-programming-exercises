#include <stdio.h>
#include <ctype.h>

void count_characters(int character_counter[]) {
  int character;
  while ((character = getchar()) != EOF) {
    ++character_counter[character];
  }
}

void make_histogram(const int character_counter[]) {
  for (int character = 0; character < 256; ++character) {
    if (isprint(character)) {
      printf("'%c':", character);
      for (int i=0; i<character_counter[i]; ++i) {
        putchar('#');
      }
      putchar('\n');
    }
  }
}
int main(void) {
  int character_counter[256] = {0};
  
  count_characters(character_counter);
  make_histogram(character_counter);

  return 0;
}
