#include <stdio.h>

void strncp(char *s, char *t, int n);
void str_ncat(char *s, char *t, int n);
int str_ncmp(char *s, char *t, int n);
void printf_char_list(char *s);

int main()
{
    char s[20] = "01234";
    char *t = "0124";
    int n = 3;

//    printf_char_list(s);

    printf("retrun: %d\n",  str_ncmp(s, t, n));
}


void strncp(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n--)
        *s++ = '\0';
}



void str_ncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    for(; n > 0 && *t; n--)
          *s++ = *t++;
}


int str_ncmp(char *s, char *t, int n)
{
    for(n--; *s == *t; n--, s++, t++) {
        if (n <= 0 || *s == '\0') {
            return 0;
        }
    }

    return *s - *t;
 }


int str_ncmp(char *s, char *t, int n)
{
    while(*s == *t) {
        n--;
        if (*s == '\0' || n == 0)
            return 0
    }
    return *s - *t;
}


void printf_char_list(char *s)
{
    printf("char_list: ");
    while(*s)
        printf("%c", *s++);
    printf("\n");
}
