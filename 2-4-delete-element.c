#include <stdio.h>
#define MAX 10

void squeeze(char s1[], char s2[]);

int main()
{
    char str1[MAX];
    char str2[MAX];
    int i = 0;
    char c;
    while (i < MAX && (c = getchar()) != EOF && c != '\n') {
        str1[i] = c;
        i++;
    }
    i = 0;
    while (i < MAX && (c = getchar()) != EOF && c != '\n') {
        str2[i] = c;
        i++;
    }
    squeeze(str1, str2);
    printf("new str: %s\n", str1);
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    k = 0;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0') {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}