/**
 * @file insertion_sort.c
 * @author rohit kulkarni
 * @brief this sorting framework just call your respective sort functions inside sort function()
 * here insertion sort is used
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

void insertion_sort(int* p_arr, int N);
void insert_at_sorting_pos(int *p_arr, int N);
void insert_at_sorting_pos_1(int *p_arr, int N); /*alternate approach*/
int main(int argc, char *argv[])
{
   time_t start_time, end_time;
    double diff_t = 0.0;

    if (argc != 2)
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
    insertion_sort(p_arr, N);
}

void insertion_sort(int* p_arr, int N)
{
    for (int i = 1; i <= N; i++)
    {
        insert_at_sorting_pos_1(p_arr, i);
    }
}

void insert_at_sorting_pos(int *p_arr, int N)
{
    int key; /* Array : [ 2 3 4 5 1 ]            */
    int i;   /* Index : [ 0 1 2 3 4 ]     N : 5  */

    key = p_arr[N - 1];
    i = N - 2;
    while (i > -1)
    {
        if (p_arr[i] > key)
        {
            p_arr[i + 1] = p_arr[i];
            i += -1;
        }
        else
        {
            break;
        }
    }
    p_arr[i + 1] = key;
}

void insert_at_sorting_pos_1(int *p_arr, int N)
{
    int key, i;

    key = p_arr[N - 1];

    for (i = N - 2; i > -1 && p_arr[i] > key; --i)
    {
        p_arr[i + 1] = p_arr[i];
    }
    p_arr[i + 1] = key;
}
