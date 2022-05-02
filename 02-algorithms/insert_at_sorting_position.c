/**
 * @file insert_at_sorting_position.c
 * @author rohit kulkarni
 * @brief   insert on index where all element of array are sorted but the last element.
 *          valid range of indices is
 *          0 < i < N-1
 *          first index = 0;
 *          last index = N-1;
 *
 * @date 2022-05-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
    PRE-CONDITION:
    p_arr[0] to p_arr[n-2] are sorted;
    but p_arr[0] to p_arr[n-1] are not sorted
    {
        Note: p_arr[n-1] is not at correct position
    }

    POST-CONDITION:
    p_arr[0] to p_arr[n-1] are sorted;
    {
        Note: Meaning that algorithm puts p_arr[n-1]
        to its right sorting position rearranging /
        moving array in process

    }
*/

void insert_at_sorting_pos(int *, int);   // basic
void insert_at_sorting_pos_1(int *, int); // polished
void print_arr(int *, int);

int main()
{

    int arr[] = {2, 3, 4, 5, 1};
    int N = sizeof(arr) / sizeof(arr[0]);

    print_arr(arr, N);
    insert_at_sorting_pos(arr, N);
    print_arr(arr, N);

    return 0;
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

void print_arr(int *p_arr, int N)
{
    printf("[ ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", p_arr[i]);
    }
    printf("]\n");
}