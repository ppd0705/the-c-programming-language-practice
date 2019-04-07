#include <stdio.h>

int power(int base, int n);
int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d %d %d\n", i, power(2, i), power(-2, i));
    }
}

int power(int base, int n)
{
    int i;
    int result = 1;
    for (i = 0; i < n; i++)
        result *= base;
    return result;
}