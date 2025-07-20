#include <stdio.h>
#define MAXLINE 1000

int get_line_from_input(char line[], int maxline) {
  int character, i;
  bool truncated = false;
  for (i=0;(character=getchar())!=EOF && character!='\n';++i) {
    if (i < maxline - 1) {
      line[i] = character;
    } else if (!truncated) {
      truncated = true;
    }
  }
  if (character == '\n' && !truncated) {
    line[i] = character;
    ++i;
  }
  if (truncated) {
    line[maxline - 2] = '\n';
    line[maxline - 1] = '\0';
  } else {
    line[i] = '\0';
  }
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

int main(void) {
  int length, max_length;
  char line[MAXLINE], longest[MAXLINE];

  max_length = 0;
  while ((length = get_line_from_input(line, MAXLINE)) > 0) {
    if (length > max_length) {
      max_length = length;
      copy(longest, line);
    }
  }
  if (max_length > 0)
    printf("%s", longest);

  return 0;
}
