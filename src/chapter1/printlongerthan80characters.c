#include <stdio.h>
#define MAXLINE 1000

int get_line_from_input(char line[], int maxline) {
  int character, i;
  for (i=0;(character=getchar())!=EOF && character!='\n';++i) {
      line[i] = character;
  }
  if (character == '\n') {
    line[i] = character;
    ++i;
  }
  line[i] = '\0';
  return i;
}

int main(void) {
  int length;
  char line[MAXLINE];

  while ((length = get_line_from_input(line, MAXLINE)) > 0) {
    if (length > 80) {
      printf("%s", line);
    }
  }
  
  return 0;
}
