#include <stdio.h>
#define MAX 10

void any(char s1[], char s2[], int pos[]);

int main()
{
    char str1[MAX];
    char str2[MAX];
    int pos[MAX];
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
    any(str2, str1, pos);
}

void any(char s1[], char s2[], int pos[])
{
    int i, j, k;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s2[j] == s1[i]) {
                pos[i] = j;
                break;
            }
        if (s2[j] == '\0')
            pos[i] = -1;
        }
    }
    for (k = 0; k < i; k++)
        printf("%d: %d\n", k, pos[k]);
}