#include <stdio.h>
#define MAX 4

int htoi(char s[]);

int main()
{
    char str[MAX];
    int i = 0;
    char c;
    while (i < MAX && (c = getchar()) != EOF && c != '\n') {
        str[i] = c;
        i++;
    }
    printf("hex: %s --> decimal : %d", str, htoi(str));
}

int htoi(char s[])
{
    int hexdigit, i, inhex, n;
    i = 0;
    if (s[i] == '0') {
        i++;
        if (s[i] == 'X' || s[i] == 'x')
            i++;
    }

    n = 0;
    inhex = 1;
    for(; inhex; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'z')
            hexdigit = s[i] - 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            hexdigit = s[i] - 'A';
        else
            inhex = 0;
        if (inhex)
            n = 16 * n + hexdigit;
    }
    return n;
}