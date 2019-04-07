#include <stdio.h>

int main()
{
    int c;
    int prev_char = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\\'){
            putchar('\\');
            putchar('\\');
        } else
            putchar(c);
    }
}