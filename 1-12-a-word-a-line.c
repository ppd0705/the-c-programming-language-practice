#include <stdio.h>

int main()
{
    int c;
    int in_word = 0;
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n' || c == '\b') {
            if (in_word) {
                putchar('\n');
                in_word = 0;
            }
        }
        else {
            putchar(c);
            in_word = 1;
        }


    }
}