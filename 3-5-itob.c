#include <stdio.h>
#include <string.h>

#define MAX 40

void reverse(char s[]);

void itob(int n, char s[], int b);

void printf_char_list(char s[], int n);

int main()
{
    int n, b;
    char s[MAX];
    printf("Input 2 int: ");
    scanf("%d %d", &n, &b);
    itob(n, s, b);
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

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}


void itob(int n, char s[], int b)
{
    int i, remain, sign;
    remain = n % b;
    printf("n: %d\n", n);
    i = 0;
    n = n / b;
    sign = 1;
    if (n < 0) {
        n = -n;
        sign = -1;
    }
    if (remain < 0) {
        sign = -1;
        remain = -remain;
    }

    if (remain > 9)
        s[i++] = remain + 'A' - 10;
    else
        s[i++] = remain + '0';
    while (n > 0) {
        remain = n % b;
        if (remain > 9)
            s[i++] = remain + 'A' - 10;
        else
            s[i++] = remain + '0';
        n /= b;
    }

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}







