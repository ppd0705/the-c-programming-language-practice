#include <stdio.h>

int strend(char *s, char *t);

int main()
{
    char *s = "34";
    char *t = "334";
    printf("strend: %d\n", strend(s, t));
}


int strend(char *s, char *t)
{
    char *s0 = s;
    char *t0 = t;
    while (*s)
        s++;
    while (*t)
        t++;
    while (*t == *s) {
        if (t == t0)
            return 1;
        else if (s == s0)
            return 0;
        t--;
        s--;
    }
    return 0;
}
