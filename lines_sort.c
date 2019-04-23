#include <stdio.h>
#include <string.h>

#define MAXLINES 5
#define MAXLEN 10




char *linept[MAXLINES];

int readlines(char *linept[], int nlines);
void writelines(char *linept[], int nlines);

void qsort(char *linept[], int left, int right);

int get_line(char *, int);

#define ALLOCSIZE  (MAXLEN * MAXLINES)
char *alloc(int);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

int main()
{
    int nlines;
    if ((nlines = readlines(linept, MAXLINES)) >= 0) {
        qsort(linept, 0, nlines -1);
        writelines(linept, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }

}


void strcp(char *s, char *t);
void strcp(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}

int readlines(char *linept[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len+1)) == NULL)
            return -1;
        else {
            line[len] = '\0';
            strcp(p, line);
            linept[nlines++] = p;

        }
    return nlines;
}


void writelines(char *linept[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", linept[i]);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left+1; i <= right; i++)
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int get_line(char line[], int max)
{
    int c;
    int i = 0;
    while ((c = getchar()) != EOF && i < max-1 && c != '\n') {
        line[i++] = c;
    }
//    if (c == '\n')
//        line[i++] = c;
    line[i] = '\0';
    return i;
}