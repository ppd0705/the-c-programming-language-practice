#include <stdio.h>

unsigned rightrot(unsigned int x, unsigned int n);

void print_bin(unsigned int num, unsigned int bytes);

int word_length(void);

int main()
{
    unsigned int x, n;
    printf("Input 2 unsigned int: ");
    scanf("%u %u", &x, &n);
    print_bin(x, sizeof(x));
    print_bin(rightrot(x, n), sizeof(x));

}

unsigned rightrot(unsigned int x, unsigned int n) {
    while (n--)
        x = (x >> 1) | (x & 1) << (word_length() * 8 - 1);
    return x;
}

void print_bin(unsigned int num, unsigned int bytes)
{
    int i =  bytes * 8; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((num >> i) & 1)); /* loop through and print the bits */
    }
    putchar('\n');
}

int word_length(void)
{
    int i;
    unsigned int  v = (unsigned int) ~0;
    for(i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}