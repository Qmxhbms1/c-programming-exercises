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

int is_space(int character) {
  return (character == ' ' || character == '\t' || character == '\n');
}

void remove_tailing_blanks(char line[], int length) {
  int i;
  int last_non_space = -1;
  for(i = 0; i < length; i++) {
    if (!is_space(line[i]))
      last_non_space = i;
  }
  line[last_non_space + 1] = '\0';
}

int main(void) {
  int length;
  char line[MAXLINE];
  while ((length=get_line_from_input(line, MAXLINE)) > 0) {
    remove_tailing_blanks(line, length);
    if (line[0] != '\0')
      printf("[%s]\n", line);
  }

  return 0;
}
