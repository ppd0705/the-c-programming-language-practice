#include <stdio.h>
#include <string.h>

#define MAX 10

void reverse(char s[]);



void printf_char_list(char s[], int n);

int main()
{
    int i;
    char s[MAX] = "abcde";

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

//void reverse(char s[])
//{
//    int c, i, j;
//    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
//        c = s[i];
//        s[i] = s[j];
//        s[j] = c;
//    }
//}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i], s[i] = s[j], s[j] = c;
    }
}






