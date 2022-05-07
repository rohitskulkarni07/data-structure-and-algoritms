#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

/*allocate and input array*/
int *allocate_and_input_array(int *p_size);

/*merge array*/
void merge(int *arr, int p, int q, int r);

/*print array*/
void print_array(int *arr, int N);

/*release array*/
void release_array(int **pp_arr);

int main(void)
{

    int *p_arr = NULL;
    int N = 0;

    p_arr = allocate_and_input_array(&N);

    printf("Complete Array Before merge: \n");
    print_array(p_arr, N);

    // sort function call here

    printf("Complete Array After merge: \n");
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
    int mid = 0;

    printf("Enter the size of the array: ");
    scanf("%d", p_size);
    assert(*p_size > 0);
    N = *p_size;

    p_arr = (int *)malloc(sizeof(int) * N);
    assert(p_arr != NULL);

    mid = N / 2;

    for (i = 0; i <= mid; ++i)
    {
        p_arr[i] = (i + 1) * 10;
    }
    for (i = mid + 1; i < N; ++i)
    {
        p_arr[i] = (i + 1) * 5;
    }

    return p_arr;
}

/*divide array into 2 and merge*/
void merge(int *p_arr, int p, int q, int r)
{
    int *pa1 = NULL;
    int *pa2 = NULL;

    int N1;
    int N2;

    int i, j, k;
    int cnt;

    N1 = q-p+1;
    N2 = r-q;

    pa1 = (int *) malloc(N1 * sizeof(int));
    assert(pa1 != NULL);
    
    pa2 = (int *) malloc(N2 * sizeof(int));
    assert(pa2 != NULL);

    i = 0;
    j = 0;
    k = 0;

    while(TRUE)
    {
        if (pa1[i] <= pa2[j])
        {
            p_arr[k + p] = pa1[i];
            i += 1;
            k += 1;
            if (i == N1)
            {
                while (j < N2)
                {
                    p_arr[k + p] = pa2[j];
                    j+=1;
                    k+=1;
                }
                break;
            }
        }
        else
        {
            p_arr[k + p] = pa2[j];
            j += 1;
            j += 1;

            if (j == N2)
            {

                while (j < N2)
                {
                    p_arr[k + p] = pa1[i];
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
    *pp_arr = NULL;
}
