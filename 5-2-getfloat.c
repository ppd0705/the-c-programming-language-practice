#include <stdio.h>
#include <ctype.h>

#define MAX 10

int buf = 0;

int getch(void);
void ungetch(int c);

void printf_char_list(char s[], int n);

int main()
{
    int n;
    int getfloat(double *);
    double array[MAX];
    for (n = 0; n < MAX && getfloat(&array[n]) != EOF; n++)
        ;
    for (n = 0; n < MAX && array[n] != EOF; n++)
        printf("%d: %g\n", n, array[n]);
}


int getfloat(double *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    *pn = 0.0;
    if (c == '-' || c == '+') {
        c = getch();
        if (isspace(c))
            return 0;
    }
    while (isdigit(c)) {
        *pn = *pn * 10.0 + c - '0';
        c = getch();
    }
    if (c == '.') {
        int power = 1.0;
        c = getch();
        while (isdigit(c)) {
            *pn = *pn * 10.0 + c - '0';
            c = getch();
            power *= 10.0;
        }
        *pn /= power;

    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    int c;
    if (buf != 0)
        c = buf;
    else
        c = getchar();
    buf =0;
    return c;
}

void ungetch(int c)
{
    if (buf == 0)
        buf = c;
    else
        printf("ungetch: tomany charaters\n");
}







