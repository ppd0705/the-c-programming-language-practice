#include <stdio.h>

int sstrcmp(char *s, char *t);

int main()
{
    char *s = "01234";
    char *t = "0124";
    printf("str cmp return: %d\n", sstrcmp(s, t));
}

//int sstrcmp(char *s, char *t)
//{
//    int i;
//    for (i = 0; s[i] == t[i]; i++) {
//        if (s[i] == '\0')
//            return 0;
//    }
//    return s[i] - t[i];
//}


int sstrcmp(char *s, char *t)
{
    while (*s == *t) {
        if (*s == '\0')
            return 0;
        s++;
        t++;
    }
    return *s - *t;
}

