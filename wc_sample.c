#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, num_line, num_word, num_char, state;
    state = OUT;
    num_line = num_word = num_char = 0;
    while ((c = getchar()) != EOF) {
        num_char++;
        if (c == '\n')
            num_line++;
        if (c == ' ' || c == '\t' || c == '\b' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            num_word++;
        }
    }
    printf("num line: %d, word: %d, char: %d", num_line, num_word, num_char);
}