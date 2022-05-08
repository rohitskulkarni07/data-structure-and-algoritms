/**
 * @file sorting_framework.c
 * @author rohit kulkarni
 * @brief this sorting framework just call your respective sort functions inside sort function()
 *
 * @date 2022-05-09
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void input(int *p_arr, int N);
void output(int *p_arr, int N);
void sort(int *p_arr, int N);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage Error:\nCorrect Useage: %s number of elements", argv[0]);
        exit(EXIT_FAILURE);
    }

    int N = atoi(argv[1]);                     /* size of array: N (user input) */
    int *arr = (int *)malloc(sizeof(int) * N); /* array allocated of size N */

    /*input and print the array with random elements*/
    input(arr, N);
    output(arr, N);

    /*sort the array*/
    sort(arr, N);

    /* print sorted array */
    output(arr, N);

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
}