#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

// Every index will be initialized by (index + 1) * 10
int *allocate_and_input_array(int *p_size);

// zip array
void zip(int *p_arr, int size);

// output array
void output_array(int *p_arr, int size, const char *msg);

// release array
void release_array(int **pp_arr);

int main(void)
{
    int *p_arr = NULL;
    int N = 0;

    p_arr = allocate_and_input_array(&N);
    output_array(p_arr, N, "Before zip:");
    zip(p_arr, N);
    output_array(p_arr, N, "After zip:");
    release_array(&p_arr);

    return (EXIT_SUCCESS);
}

// Every index will be initialized by (index + 1) * 10
int *allocate_and_input_array(int *p_size)
{
    int *p_arr = NULL;
    int N;
    int i;

    printf("Enter the size of array:");
    scanf("%d", p_size);
    assert(*p_size > 0);
    N = *p_size;

    p_arr = (int *)malloc(N * sizeof(int));
    assert(p_arr != NULL);

    for (i = 0; i < N; ++i)
    {
        p_arr[i] = (i + 1) * 10;
    }
    return (p_arr);
}

// zip array
void zip(int *p_arr, int size)
{
    int *pa1 = NULL;
    int N1;

    int *pa2 = NULL;
    int N2;

    int mid = size / 2;
    int i, j, k;

    N1 = mid + 1;
    N2 = size - mid - 1;

    assert(N1 > 0 && N2 > 0);

    pa1 = (int *)malloc(N1 * sizeof(int));
    assert(pa1 != NULL);

    pa2 = (int *)malloc(N2 * sizeof(int));
    assert(pa2 != NULL);

    for (i = 0; i < N1; ++i)
        pa1[i] = p_arr[i];

    for (i = 0; i < N2; ++i)
        pa2[i] = p_arr[mid + 1 + i];

    i = 0;
    j = 0;
    k = 0;

    while (TRUE)
    {
        if (k % 2 == 0)
        {
            p_arr[k] = pa1[i];
            i = i + 1;
            k = k + 1;
            if (i == N1)
            {
                while (j < N2)
                {
                    p_arr[k] = pa2[j];
                    j = j + 1;
                    k = k + 1;
                }
                break;
            }
        }
        else
        {
            p_arr[k] = pa2[j];
            j = j + 1;
            k = k + 1;
            if (j == N2)
            {
                while (i < N1)
                {
                    p_arr[k] = pa1[i];
                    i = i + 1;
                    k = k + 1;
                }
                break;
            }
        }
    }

    free(pa1);
    pa1 = NULL;

    free(pa2);
    pa2 = NULL;
}
// output array
void output_array(int *p_arr, int size, const char *msg)
{
    int i;

    if (msg)
        puts(msg);
    for (i = 0; i < size; ++i)
        printf("p_arr[%d]:%d\n", i, p_arr[i]);
}
// release array
void release_array(int **pp_arr)
{
    int *p_arr = NULL;

    p_arr = *pp_arr;
    free(p_arr);
    *pp_arr = NULL;
}

//  int mid = N / 2

//  [0....mid] -> mid - 0 + 1 | N1 == mid+1;
//  [mid+1 ... N-1] -> N-1 - (mid+1) - 1 -> N - 1 - mid - 1 + 1 |
//  N2  == N - mid - 1