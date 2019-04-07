#include <stdio.h>
#include <limits.h>

int main2();

int main()
{
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
//    printf("signed short int min: %d\n", SHRT_MIN);
//    printf("signed short int max: %d\n", SHRT_MAX);
//    printf("signed int min: %d\n", INT_MIN);
//    printf("signed int max: %d\n", INT_MAX);
//    printf("signed long int min: %ld\n", LONG_MIN);
//    printf("signed long int max: %ld\n", LONG_MAX);

    printf("unsigned char max: %u\n", UCHAR_MAX);
//    printf("unsigned short int max: %u\n", USHRT_MAX);
//    printf("unsigned long int max: %lu\n", ULONG_MAX);
//    printf("unsigned int max: %u\n", UINT_MAX);

    main2();
}


int main2()
{
    printf("signed char min: %d\n",-(((unsigned char) ~0 >> 1 ) + 1));
    printf("signed char max: %d\n",(unsigned char) ~0 >> 1 );
    printf("unsigned char max: %d\n",(unsigned char) ~0);

    return 0;
}