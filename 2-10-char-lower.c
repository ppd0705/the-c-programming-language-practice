#include <stdio.h>

char char_lower(char c);

int main()
{
    char x;
    printf("Input 1 char: ");
    scanf("%c:", &x);
    printf("output: %c\n", char_lower(x));

}

char char_lower(char c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}