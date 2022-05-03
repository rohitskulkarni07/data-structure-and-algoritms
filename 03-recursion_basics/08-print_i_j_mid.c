#include <stdio.h>
#include <stdlib.h>

void f(int, int);

int main()
{

    int N = 8;

    f(1, N);
    return (0);
}

void f(int i, int j)
{
    printf("i = %d | j = %d | mid = %d\n", i, j, ((i+j)/2));
    int mid;
    if (i < j)
    {
        mid = (i+j)/2;
        f(i, mid);
        f(mid+1, j);
    }
}