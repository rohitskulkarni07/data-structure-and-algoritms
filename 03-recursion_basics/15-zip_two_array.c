#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

/*allocate and input array*/
int *allocate_and_input_array(int *p_size);

/*zip array*/
void zip(int *arr, int size);

/*print array*/
void print_array(int *arr, int N);

/*release array*/
void release_array(int **pp_arr);

int main(void)
{

    int *p_arr = NULL;
    int N = 0;

    p_arr = allocate_and_input_array(&N);

    printf("Complete Array Before Zip: \n");
    print_array(p_arr, N);

    zip(p_arr, N);

    printf("Complete Array After Zip: \n");
    print_array(p_arr, N);

    release_array(&p_arr);

    return (EXIT_SUCCESS);
}

/*allocate and input array*/
int *allocate_and_input_array(int *p_size)
{

    int *p_arr = NULL;
    int N = 0;
    int i = 0;

    printf("Enter the size of the array: ");
    scanf("%d", p_size);
    assert(*p_size > 0);
    N = *p_size;

    p_arr = (int *)malloc(sizeof(int) * N);
    assert(p_arr != NULL);

    for (i = 0; i < N; ++i)
    {
        p_arr[i] = (i + 1) * 10;
    }

    return p_arr;
}

/*divide  array into 2and zip the array*/
void zip(int *p_arr, int size)
{

    int *pa1 = NULL;
    int N1 = 0;

    int *pa2 = NULL;
    int N2 = 0;

    int mid = size / 2;
    int i = 0, j = 0, k = 0;

    // size = 10 , mid = 5, n1 = 6, n2 = 4;
    N1 = mid + 1;
    N2 = size - mid - 1;

    assert(!(N1 <= 0 && N2 <= 0));

    pa1 = (int *)malloc(sizeof(int) * N1);
    assert(pa1 != NULL);

    pa2 = (int *)malloc(sizeof(int) * N2);
    assert(pa2 != NULL);

    for (i = 0; i < N1; ++i)
    {
        pa1[i] = p_arr[i];
    }
    for (i = 0; i < N2; ++i)
    {
        pa2[i] = p_arr[mid + 1 + i];
    }
    printf("Array 1: \n");
    print_array(pa1, N1);

    printf("Array 2: \n");
    print_array(pa2, N2);

    i = 0;
    j = 0;
    k = 0;

    while (TRUE)
    {
        if (k % 2 == 0)
        {
            p_arr[k] = pa1[i];
            i += 1;
            k += 1;

            if (i == N1)
            {
                while (j < N2)
                {
                    p_arr[k] = pa2[j];
                    j += 1;
                    k += 1;
                }
                break;
            }
        }
        else
        {
            p_arr[k] = pa2[j];
            j += 1;
            k += 1;

            if (j == N2)
            {

                while (i < N1)
                {
                    p_arr[k] = pa1[i];
                    i += 1;
                    k += 1;
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

/*show array*/
void print_array(int *p_arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("[%d] ", p_arr[i]);
    }
    printf("\n");
}

/*release array*/
void release_array(int **pp_arr)
{
    int *p_arr = NULL;
    p_arr = *pp_arr;
    free(p_arr);
    *p_arr = NULL;
}
