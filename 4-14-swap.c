#include <stdio.h>
#include <string.h>

#define MAX 10

#define max(a, b) ((a) > (b) ? (a): (b))
#define square(x) (x) * (x)
#define swap(t, x, y) { \
    t temp; \
    temp = x; \
    x = y; \
    y = temp; \
}

void printf_char_list(char s[], int n);

int main()
{
    int i;
    char s[MAX] = "abcdef";


    i = max(3 , 4);
    printf("%d \n", i);
    int x = 3;
    int y = 1;
    swap(int, x, y);
    printf("%d %d\n", x, y);
    i = square((3+1));
    printf("%d \n", i);
}


void printf_char_list(char s[], int n)
{
    int i;
    printf("char_list: ");
    for (i = 0; i < n && s[i] != '\0'; i++)
        printf("%c", s[i]);
    printf("\n");
}







