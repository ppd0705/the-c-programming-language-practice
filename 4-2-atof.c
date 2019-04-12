#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 12


int get_line(char line[], int max);

double atof(char s[]);


int main()
{
    char line[MAX];
    while(get_line(line, MAX) > 0) {
        printf("\t%g\n", atof(line));
        }

    return 0;
}


int get_line(char line[], int max)
{
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < MAX-1) {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

double atof(char s[])
{
    int i, sign, index, index_sign, power;
    double val;
    val = 0;
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '-' || s[i] == '+')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
        val = 10 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for(power=0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power -= 1.0;
    }
     if (s[i] == 'e' || s[i] == 'E')
        i++;
     index_sign = (s[i] == '-') ? -1 : 1;
     if (s[i] == '-' || s[i] == '+')
        i++;
     for (index=0.0; isdigit(s[i]); i++)
        index = 10.0 * index + (s[i] - '0');
    val  = sign * val * pow(10.0, power + index_sign * index);
    return val;
}






