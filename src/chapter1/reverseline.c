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

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void reverse_string(char line[], int length) {
  int i;
  char newline[length];
  copy(newline, line);
  for (i = 0; i < length - 1; i++) {
    line[i] = newline[length - 2 - i];
  }
}

int main(void) {
  int length;
  char line[MAXLINE];
  while ((length = get_line_from_input(line, MAXLINE)) > 0) {
    reverse_string(line, length);
    printf("%s", line);
  }

  return 0;
}
