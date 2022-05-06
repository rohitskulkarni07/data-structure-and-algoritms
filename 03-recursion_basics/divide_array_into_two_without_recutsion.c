#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int N);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    int size_of_array = sizeof(arr) / sizeof(arr[0]);

    int arr_left[(size_of_array / 2)];
    int arr_right[(size_of_array / 2) - 1];
    int i, j;
    for (i = 0, j = ((size_of_array / 2)); i < ((size_of_array / 2)); ++i, j++)
    {
        arr_left[i] = arr[i];
        arr_right[i] = arr[j];
        printf("i = %d j = %d\n", i, j);
    }
    print_array(arr, size_of_array);
}

void print_array(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}