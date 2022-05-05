#include <stdio.h>
#include <stdlib.h>

void print_array_both_from_ends(int *, int, int);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int N = sizeof(arr)/sizeof(arr[0]);
    print_array_both_from_ends(arr, 0, N - 1);
    return (0);
}

void print_array_both_from_ends(int *arr, int i, int j)
{
    if (i < j)
    {
        printf("%d | %d |\n", arr[i], arr[j]);
        print_array_both_from_ends(arr, i + 1, j - 1);
    }
    else if (i == j)
    {
        printf("%d |\n", arr[i]);
        print_array_both_from_ends(arr, i + 1, j - 1);
    }
}
