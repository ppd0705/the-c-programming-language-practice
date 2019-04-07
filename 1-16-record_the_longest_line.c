#include <stdio.h>
#define MAX_LINE 1000

int get_line(char s[], int limit);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAX_LINE];
    char longest[MAX_LINE];

    max = 0;
    while ((len = get_line(line, MAX_LINE)) > 0) {
        printf("len: %d, str: %s\n", len, line);
    }
    return 0;
}

int get_line(char s[], int limit)
{
    int c, i;
    for (i = 0; i < limit -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
