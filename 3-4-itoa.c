#include <stdio.h>
#include <string.h>

#define MAX 12

void reverse(char s[]);

void itoa(int n, char s[]);

void printf_char_list(char s[], int n);

int main()
{
    int i;
    char s[MAX];
    printf("Input a int: ");
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

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}


void itoa(int n, char s[])
{
    int i, remain, sign;
    remain = n % 10;
    i = 0;
    n = n / 10;
    sign = 1;
    if (n < 0) {
        n = -n;
        sign = -1;
    }
    if (remain < 0) {
        sign = -1;
        remain = -remain;
    }

    s[i++] = remain + '0';
    while (n > 0) {
        s[i++] = n % 10 + '0';
        n /= 10;
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}




//#define abs(x) ((x) < 0 ? -(x) : (x))

//method2

//void itoa(int n, char s[])
//{
//    int sign;
//    int i = 0;
//    sign = n;
//    do {
//        s[i++] = abs(n % 10) + '0';
//    } while ((n /= 10) != 0);
//
//    if (sign < 0)
//        s[i++] = '-';
//    s[i] = '\0';
//    reverse(s);
//}



