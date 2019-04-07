#include <stdio.h>

int main()
{
    int c;
    int space_num, table_num, return_num;
    space_num = table_num = return_num = 0;
    printf("the value of EOF is %d\n", EOF);
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ')
            space_num ++;
        else if (c == '\t')
            table_num ++;
        else if (c == '\n')
            return_num ++;
    }
    printf("space: %d, table: %d, return: %d\n", space_num, table_num, return_num);

}