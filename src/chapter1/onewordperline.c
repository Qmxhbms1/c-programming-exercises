#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define OUT 0
#define IN 1

struct Word {
    char text[MAX_WORD_LEN];
    int length;
};

struct Word words[1000];
int word_count = 0;
int max_word_len = 0;

void process_first_pass(int c, int *state, int *letter_counter, char *current_word) {
    static int pos = 0;  
    
    if (*state == IN) {
        if (isspace(c)) {
            current_word[pos] = '\0';
            words[word_count].length = *letter_counter;
            strcpy(words[word_count].text, current_word);
            
            if (*letter_counter > max_word_len) {
                max_word_len = *letter_counter;
            }
            
            word_count++;
            *letter_counter = 0;
            pos = 0;
            *state = OUT;
        } else {
            current_word[pos++] = c;
            (*letter_counter)++;
        }
    } else {
        if (!isspace(c)) {
            *state = IN;
            current_word[pos++] = c;
            (*letter_counter)++;
        }
    }
}

void print_aligned_histogram(void) {
    for (int i = 0; i < word_count; i++) {
        printf("%-*s ", max_word_len, words[i].text);
        for (int j = 0; j < words[i].length; j++) {
            printf("#");
        }
        printf("\n");
    }
}

int main(void) {
    int c, state = OUT, letter_counter = 0;
    char current_word[MAX_WORD_LEN];
    
    while ((c = getchar()) != EOF) {
        process_first_pass(c, &state, &letter_counter, current_word);
    }
    
    rewind(stdin);
    print_aligned_histogram();
    
    return 0;
}
