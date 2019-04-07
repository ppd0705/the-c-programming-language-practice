#include <stdio.h>

int bitcount(unsigned int x);

int main()
{
    unsigned int x;
    printf("Input 1 unsigned int: ");
    scanf("%u:", &x);
    printf("bitcount of %u: %d\n", x, bitcount(x));

}

//int bitcount(unsigned int x)
//{
//    int i, c;
//    c = 0;
//    for (i = 0; x > 0; x >>= 1) {
//        if (x & 1)
//            i++;
//    }
//    return i;
//}

int bitcount(unsigned int x)
{
    int i;
    for (i = 0; x; x &= x - 1)
            i++;
    return i;
}