/**
 * @file merge_sort.c
 * @author rohit kulkarni
 * @brief this sorting framework just call your respective sort functions inside sort function()
 * here merge sort is used
 * @date 2022-05-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define TRUE 1

void input(int *p_arr, int N);
void output(int *p_arr, int N);
void sort(int *p_arr, int N);

void merge_sort(int *p_arr, int p, int q);
void merge(int *p_arr, int p, int q, int r);

int main(int argc, char *argv[])
{
    time_t start_time, end_time;
    double diff_t = 0.0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage Error:\nCorrect Useage: %s number of elements", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);                     /* size of array: N (user input) */
    int *arr = (int *)malloc(sizeof(int) * N); /* array allocated of size N */

    /*input and print the array with random elements*/
    input(arr, N);
    printf("Before Sorting: \n");
    output(arr, N);

    time(&start_time);

    /*sort the array*/
    sort(arr, N);

    time(&end_time);
    diff_t = difftime(end_time, start_time);

    printf("After Sorting: \n");
    /* print sorted array */
    output(arr, N);

    printf("Time required to sort : %lf\n", diff_t);
    return (0);
}

/**
 * @brief Fill the given array with random elements
 *
 * @param p_arr array
 * @param N     size of array
 */
void input(int *p_arr, int N)
{
    for (int i = 0; i < N; ++i)
    {
        int temp = rand();
        p_arr[i] = (temp % N) + 1; /*random number in range of 1 to N*/
    }
}

/**
 * @brief show the given array with random elements
 *
 * @param p_arr array
 * @param N     size of array
 */
void output(int *p_arr, int N)
{
    for (int i = 0; i < N; ++i)
    {
        printf("arr[%d] = %d\n", i, p_arr[i]);
    }
}

/**
 * @brief boiler plate to use any sort here
 *
 * @param p_arr input array to be sort
 * @param N array size
 */
void sort(int *p_arr, int N)
{
    merge_sort(p_arr, 0, N - 1);
}

/**
 * @brief merge sort algorithm
 *
 * @param p_arr array tom sort
 * @param p starting index of the array
 * @param r ending index of the array
 */

void merge_sort(int *p_arr, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(p_arr, p, q);
        merge_sort(p_arr, q + 1, r);
        merge(p_arr, p, q, r);
    }
}

void merge(int *p_arr, int p, int q, int r)
{
    int *pa1 = NULL;
    int *pa2 = NULL;

    /* calculate the size for both arrays to allocate */
    int N1 = q - p + 1;
    int N2 = r - q;

    assert(!(N1 == 0 && N2 == 0));

    pa1 = (int *)malloc(sizeof(int) * N1);
    assert(pa1 != NULL);

    pa2 = (int *)malloc(sizeof(int) * N2);
    assert(pa2 != NULL);

    int i = 0, j = 0, k = 0;
    int count = 0;

    for (count = 0; count < N1; ++count)
    {
        pa1[count] = p_arr[p + count];
    }

    for (count = 0; count < N2; ++count)
    {
        pa2[count] = p_arr[q + 1 + count];
    }

    while (TRUE)
    {
        if (pa1[i] <= pa2[j])
        {
            p_arr[p + k] = pa1[i];
            i += 1;
            k += 1;

            if (i == N1)
            {
                while (j < N2)
                {
                    p_arr[p + k] = pa2[j];
                    j += 1;
                    k += 1;
                }
                break;
            }
        }
        else
        {

            p_arr[p + k] = pa2[j];
            j += 1;
            k += 1;

            if (j == N2)
            {
                while (i < N1)
                {
                    p_arr[p + k] = pa1[i];
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