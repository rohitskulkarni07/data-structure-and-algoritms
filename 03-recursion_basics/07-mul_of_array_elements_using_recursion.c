#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned long long int N;             /* number of array elements */
unsigned long long int *g_ptr = NULL; /* array */

int sum_arr(int);
unsigned long long int mul_arr(unsigned long long int *, unsigned long long int);

int main(void)
{
    printf("Enter the array size: ");
    scanf("%llu", &N);

    g_ptr = (unsigned long long int *)malloc(sizeof(unsigned long long int) * N);
    assert(g_ptr != NULL);
    for (unsigned long long int i = 0; i < N; i++)
    {
        *(g_ptr + i) = i + 1;
    }
    unsigned long long int mul = mul_arr(g_ptr, N);
    printf("multiplication of all the array elements is: %llu\n", mul);
    free(g_ptr);
    g_ptr = NULL;
}

unsigned long long int mul_arr(unsigned long long int *arr, unsigned long long int size)
{
    return (size > 0) ? (arr[0] * mul_arr(arr + 1, size - 1)) : (1);
}