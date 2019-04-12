#include <stdio.h>
#include <string.h>

#define MAX 12


int get_line(char line[], int max);

int strindex(char source[], char searchfor[]);

char pattern[] = "ould";


int main()
{
    char line[MAX];
    int found = 0;
    while(get_line(line, MAX) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}


int get_line(char line[], int max)
{
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < MAX-1) {
        line[i++] = c;
    }
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

//method 1
//int strindex(char source[], char searchfor[])
//{
//    int p, i, j, k;
//    p = -1;
//    for (i = 0; source[i] != '\0'; i++) {
//        for (j=i,k=0;  searchfor[k] != '\0' && source[j] == searchfor[k]; k++,j++)
//            ;
//        if (searchfor[k] == '\0')
//            p = i;
//    }
//    return p;
//}


int strindex(char source[], char searchfor[])
{
    int i, j, k;
    for (i = strlen(source) - strlen(searchfor); i >= 0; i--) {
        for (j=i,k=0;  searchfor[k] != '\0' && source[j] == searchfor[k]; k++,j++)
            ;
        if (searchfor[k] == '\0')
            return i;
    }
    return -1;
}











