#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 12

void itoa(int n,char s[]);

void printf_char_list(char s[], int n);

int main()
{
    int i;
    char s[MAX];
    scanf("%d", &i);
    itoa(i, s);
    printf_char_list(s, MAX);
}


void printf_char_list(char s[], int n)
{
    int i;
    printf("char_list: ");
    for (i = 0; i < n && s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf("\n");
}


void itoa(int n, char s[])
{
    static int i;
    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = abs(n) % 10 + '0' ;
    s[i] ='\0';
}






