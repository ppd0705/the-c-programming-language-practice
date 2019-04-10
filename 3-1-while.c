#include <stdio.h>
#define MAX 10

int binsearch(int x, int v[], int n);

int main()
{
    int x, v[MAX];
    int i;
    printf("Input 1 integer you find: ");
    scanf("%d:", &x);
    printf("Input %d integer ordered list: ", MAX);
    for (i = 0; i < MAX; i++)
        scanf("%d:", &v[i]);
    printf("index: %d\n", binsearch(x, v, MAX));

}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (high + low) / 2;
    while(v[mid] != x && low<=high) {
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
        mid = (high + low) / 2;
    }
    if (v[mid] == x)
        return mid;
    else
        return -1;
}
