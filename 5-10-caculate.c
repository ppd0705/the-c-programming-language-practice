#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100
#define MAXLINE 100

double val[MAXOP];
int sp = 0;

int getop(char s[]);
void push (double f);
double pop(void);
int isnumfmt(char s[]);

int main(int argc, char *argv[])
{
    char *t;
    double op2;
    while (--argc > 0) {
        t = *++argv;
        if (isnumfmt(t)) {
          push(atof(t));
        } else if (!strcmp(t, "+")) {
          push(pop() + pop());
        } else if (!strcmp(t, "*")) {
        // FIXME '*' is a spacial sign
          push(pop() * pop());
        } else if (!strcmp(t, "-")) {
          op2 = pop();
          push(pop() - op2);
        } else if (!strcmp(t, "/")) {
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else {
                push(0.0);
                printf("error: zero divisor\n");
             }
        } else
            printf("error: unknown command %s \n", t);
    }
    printf("result: \t%.8g\n", pop());
    return 0;
}

void push(double f)
{
    if (sp < MAXOP)
        val[sp++] = f;
    else
        printf("error: stack full [%i/%i], can't push %g\n", sp, MAXOP, f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: empty stack");
        return 0;
    }
}

int isnumfmt(char s[]) {
    int i = 0, c;

    if ((c = s[i]) == '+' || c == '-') {
        i++;
    }

    if (s[i] == '\0') {
        return 0;
    }

    for (; isdigit(c = s[i]); i++);

    if (c == '.') {
        i++;
    }

    for (; isdigit(c = s[i]); i++);

    if (c == 'e' || c == 'E') {
        int c2 = s[i + 1];
        int c3 = s[i + 2];
        if ((c2 == '+' || c2 == '-') && isdigit(c3)) {
            i += 2;
        } else if (isdigit(c2)) {
            i++;
        }
    }

    for (; isdigit(c = s[i]); i++);

    return c == '\0';
}
