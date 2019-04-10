#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX2 26 * 3 + 1

void expand(char s1[], char s2[]);

void printf_char_list(char s[], int n);

int main()
{
    int i = 0;
    char c;
    char s1[MAX];
    char s2[MAX2];
    printf("Input string: ");
    while ((c = getchar()) != EOF && c != '\n' && i < MAX -1)
        s1[i++] = c;
    s1[i] = '\0';
    printf_char_list(s1, MAX);
    expand(s1, s2);

    printf_char_list(s2, MAX2);
}


void printf_char_list(char s[], int n)
{
    int i;
    printf("char_list: ");
    for (i = 0; i < n && s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf("\n");
}



void expand(char s1[], char s2[])
{
    int i, j, k, c;
    k = 0;
    j = strlen(s1) - 1;

    for (i = 0; i <= j-2;) {
        if (s1[i+1] == '-' && s1[i] <= s1[i+2] && ((s1[i] >= '0' && s1[i+2] <= '9') ||
        (s1[i] >= 'a' && s1[i+2] <= 'z')  || (s1[i] >= 'A' && s1[i+2] <= 'Z'))) {
            if (s1[i] < s1[i+2]) {
                for(c=s1[i]; c<=s1[i+2]; c++)
                    s2[k++] = c;
                i += 3;
            } else
                s2[k++] = s1[i++];
        } else
            s2[k++] = s1[i++];
    }
    while (i <= j)
        s2[k++] = s1[i++];
    s2[k] = '\0';
}




