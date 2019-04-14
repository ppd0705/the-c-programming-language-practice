#include <stdio.h>
#include <unistd.h>

#define MAX 10

void swap(int v[], int i, int j);
void qsort(int v[], int left, int right);

void printf_int_list(int v[], int n);

int main()
{
    int i, v[MAX];
    printf("Input %d int: ", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &v[i]);

    printf_int_list(v, MAX);

    qsort(v, 0, MAX-1);

    printf_int_list(v, MAX);
}

void printf_int_list(int v[], int n)
{
    int i;
    printf("int_list: ");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}


void qsort(int v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;``
    for(i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}