#include <stdio.h>

void sstrcat(char *s, char *t);
void printf_char_list(char *s);

int main()
{
    char s[20] = "01234";
    char *t = "56789";
    sstrcat(s, t);
    printf_char_list(s);
}


void sstrcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*t)
        *s++ = *t++;
}

void printf_char_list(char *s)
{
    printf("char_list: ");
    while(*s)
        printf("%c", *s++);
    printf("\n");
}
