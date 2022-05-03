#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int N; /* number of array elements */
int *g_ptr = NULL;

int sum_arr(int);
int sum_arr_1(int *, int);

int main(void)
{
    printf("Enter the array size: ");
    scanf("%d", &N);

    g_ptr = (int *)malloc(sizeof(int) * N);
    assert(g_ptr != NULL);
    for (int i = 0; i < N; i++)
    {
        *(g_ptr + i) = i + 1;
    }
    // int sum = sum_arr(0);
    int sum = sum_arr_1(g_ptr, N);
    printf("sum of all the array elements is: %d\n", sum);
    free(g_ptr);
    g_ptr = NULL;
}

int sum_arr(int index)
{
    static int sum = 0;
    if (index == N)
    {
        return 0;
    }

    sum += g_ptr[index];
    sum_arr(index + 1);

    return sum;
}

int sum_arr_1(int *arr, int size)
{
    return (size > 0) ? (arr[0] + sum_arr_1(arr + 1, size - 1)) : (0);
}