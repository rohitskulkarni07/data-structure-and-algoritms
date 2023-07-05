/**
 * @file quick_sort.c
 * @author rohit kulkarni
 * @brief quick sort algorithm generic implementation
 * @date 2022-05-09
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void input(int *p_arr, int N);
void output(int *p_arr, int N);
void sort(int *p_arr, int N);

void quick_sort(int *arr, int p, int r);
int partition(int *arr, int p, int r);

int main(int argc, char *argv[])
{
    time_t start_time, end_time;
    double diff_t = 0.0;

    if (argc != 2)
    {
        fprintf(stderr, "Usage Error:\nCorrect Usage: %s number of elements", argv[0]);
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
    exit(EXIT_SUCCESS);
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
    quick_sort(p_arr, 0, N - 1);
}

/**
 * @brief recursive function which returns the sorted array if give unsorted array
 *
 * @param arr un-sorted array
 * @param p starting index
 * @param r ending index
 */
void quick_sort(int *arr, int p, int r)
{

    int q;

    if (p < r)
    {
        q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}
/**
 * @brief partition the array in such way it pivot should be at correct possition
 * where a[p ... i] are less than pivot and [i+1...r] are greater than pivot
 *
 * @param arr unsorted array
 * @param p starting index
 * @param r ending index
 * @return int position of pivot after sorting
 */
int partition(int *arr, int p, int r)
{
    int pivot;
    int i, j, temp;

    pivot = arr[r];
    i = p - 1;
    for (j = p; j < r; ++j)
    {
        if (arr[j] <= pivot)
        {
            i = i + 1;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = pivot;
    arr[r] = temp;

    return (i + 1);
}
