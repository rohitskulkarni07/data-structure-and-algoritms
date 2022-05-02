/**
 * @file insertion_sort_user_input.c
 * @author rohit kulkarni
 * @brief   insertion sort with
 *
 * @date 2022-05-02
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insert_at_sorting_pos(int *, int);   // basic
void insert_at_sorting_pos_1(int *, int); // polished
void insertion_sort(int*, int);
int *fill_array(int *);
void print_arr(int *, int);
void release_arr(int**);

int main()
{

    int *arr = NULL;
    int N = 0;
    arr = fill_array(&N);

    print_arr(arr, N);
    insertion_sort(arr, N);
    print_arr(arr, N);

    release_arr(&arr);

    return 0;

}

int* fill_array(int* N) {

    int *arr = NULL;
    int array_length = 0;
    int data = 0;
    printf("Enter size of array: ");
    scanf("%d", &array_length);

    *N = array_length;
    
    arr = (int*)malloc(sizeof(int) * array_length);
    
    assert(arr!=NULL);

    printf("Enter array elements: \n[ ");
    for(int i = 0; i < array_length; i++) {
        scanf("%d", &data);
        arr[i] = data;
    }
    printf(" ]\n");

    return(arr);
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

void release_arr(int** pp_arr)
{
    int *p = *pp_arr;
    free(p);
    p = NULL;
    *pp_arr = NULL;
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