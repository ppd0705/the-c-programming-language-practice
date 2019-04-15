#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define MAXVAL 10
#define BUFSIZE 100

char buf;
int sp = 0;
double val[MAXVAL];


int gettop(char s[]);
void push (double f);
double pop(void);
int getch(void);
void ungetch(int);
void clear_stack(void);
void mathfunc(char s[]);

int main()
{
    int type, i, var = 0;
    double op1, op2, v;
    char s[MAXOP];
    double variable[26];

    for(i = 0; i < 26; i++)
        variable[i] = 0.0;

    while ((type = gettop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfunc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = (int) pop();
            if (op2 != 0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '?':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear_stack();
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            op1 = pop();
            push(op1);
            push(op2);
            break;
        case '=':
            pop();
            if (var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("error: no variable name\n");
            break;
        case '\n':
            v = pop();
            printf("\t%.8g\n", v);
            break;
        default:
            if (type >= 'A' && type <= 'Z')
                push(variable[type - 'A']);
            else if (type == 'v')
                push(v);
            else
                printf("error: unkown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full [%i/%i], can't push %g\n", sp, MAXVAL, f);
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


int gettop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    i = 0;

    if(islower(c)) {
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else
            return c;
    }

    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }
     if (! isdigit(c) && c != '.')
        return c;

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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

void ungets(char s[])
{
    unsigned long l;
    l = strlen(s);
    while (l > 0)
        ungetch(s[--l]);
}


void clear_stack(void)
{
    sp = 0;
}

void mathfunc(char s[]) {
    double op2;
    if (strcmp(s, "sin") == 0 )
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: %s not supported\n", s);
}