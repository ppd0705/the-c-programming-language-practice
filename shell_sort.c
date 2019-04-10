#include <stdio.h>

#define MAX 10

void shellsort(int v[], int n);

void shellsort2(int v[], int n);

void printf_int_list(int v[], int n);

int main()
{
    int i, v[MAX];
    printf("Input %d int: ", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d", &v[i]);

    printf_int_list(v, MAX);

    shellsort2(v, MAX);

    printf_int_list(v, MAX);
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

void printf_int_list(int v[], int n)
{
    int i;
    printf("int_list: ");
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

void shellsort2(int v[], int n) {
    int gap, i, j;
    int temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++) {
            temp = v[i];
            for (j = i - gap; j >= 0 && v[j] > temp; j -= gap)
               v[j+gap] = v[j];
            v[j+gap] = temp;
        }
}

