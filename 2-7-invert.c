#include <stdio.h>

unsigned setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y);

unsigned invert(unsigned int x, unsigned int p, unsigned int n);
unsigned getbits(unsigned int x, unsigned int p, unsigned int n);

void print_bin(unsigned int num, unsigned int bytes);

int main()
{
    unsigned int x, n, p;
    printf("Input 3 unsigned int: ");
    scanf("%u %u %u", &x, &p, &n);
    print_bin(x, sizeof(x));
    print_bin(invert(x, p, n), sizeof(x));

}

//method 1
//unsigned invert(unsigned int x, unsigned int p, unsigned int n)
//{
//    unsigned int y;
//    y = ~getbits(x, p, n) & ~(~0 << n) & ~(~0 << n);
//    return (setbits(x, p, n, y));
//}

unsigned invert(unsigned int x, unsigned int p, unsigned int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}


unsigned getbits(unsigned int x, unsigned int p, unsigned int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned int x, unsigned int p, unsigned int n, unsigned int y)
{
    return (x & ~(~(~0 << n) << (p+1-n))) | (y & (~(~0 << n) << (p+1-n)));
}

void print_bin(unsigned int num, unsigned int bytes)
{
    int i =  bytes * 8; /* however many bits are in a byte on your platform */
    while(i--) {
        putchar('0' + ((num >> i) & 1)); /* loop through and print the bits */
    }
    putchar('\n');
}