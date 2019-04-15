#include <stdio.h>
#include <string.h>

#define MAX 10


void reverse(char s[]);


void printf_char_list(char s[], int n);

int main()
{
    int i;
    char s[MAX] = "abcdef";

    printf_char_list(s, MAX);

    reverse(s);

    printf_char_list(s, MAX);
}


void printf_char_list(char s[], int n)
{
    int i;
    printf("char_list: ");
    for (i = 0; i < n && s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf("\n");
}

void reverser(char s[], int i, int len)
{
    int temp, j;
    j = len - 1 - i;
    if (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverser(s, ++i, len);
    }
}

void reverse(char s[])
{
   void reverser(char s[], int i, int len);

   reverser(s, 0 , strlen(s));
}






