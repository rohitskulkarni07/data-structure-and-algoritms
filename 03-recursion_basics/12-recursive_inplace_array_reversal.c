#include <stdio.h>
#include <stdlib.h>

void array_reverse_inplace(int *arr, int i, int j);
void print_array(int *, int);

int main()
{
    int arr[] = {2, 4, 1, 3, 7, 9, 5, 8, 6, 10};
    int N = sizeof(arr) / sizeof(arr[0]);

    puts("Array before reversal");
    print_array(arr, N);

    array_reverse_inplace(arr, 0, N - 1);

    puts("\nArray after reversal");
    print_array(arr, N);

    return (EXIT_SUCCESS);
}

void print_array(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("[%d] ", arr[i]);
    }
    printf("\n");
}

void array_reverse_inplace(int *arr, int i, int j)
{

    if (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        array_reverse_inplace(arr, i + 1, j - 1);
    }
}