#include <stdio.h>
#define MAX 10

unsigned setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);


void print_bin(unsigned int num, unsigned int bytes);

int main()
{
    unsigned int x, y, n, p;
    printf("Input 4 unsigned int: ");
    scanf("%u %u %u %u", &x, &p, &n, &y);
    print_bin(x, sizeof(x));
    print_bin(y, sizeof(y));

    print_bin(setbits(x, p, n, y), sizeof(x));

}

unsigned setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
    unsigned left, right, base;
    left = ~0 << (p + 1);
    right = (unsigned int) ~0 >> (sizeof(p) * 8 - (p + 1 - n));
    base = left | right;
    return (x & base) | (~base & y);
}

//method 2
//unsigned setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
//{
//    return (x & ~(~(~0 << n) << (p+1-n))) | (y & (~(~0 << n) << (p+1-n)));
//}



void print_bin(unsigned int num, unsigned int bytes)
{
    int i =  bytes * 8; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((num >> i) & 1)); /* loop through and print the bits */
    }
    putchar('\n');
}