#include <stdio.h>
#include <stdlib.h>

int find_max(int *arr, int i, int N);

int main()
{
    int arr[] = {2, 4, 1, 3, 7, 9, 5, 8, 6, 10};
    int N = sizeof(arr) / sizeof(arr[0]);
    int max = find_max(arr, 0, N - 1);

    printf("max element = %d\n", max);
    return (EXIT_SUCCESS);
}

int find_max(int *arr, int i, int j)
{
    int mid;
    int max_l;
    int max_r;

    if (i == j)
    {
        return (arr[i]);
    }
    else
    {
        mid = (i + j) / 2;
        max_l = find_max(arr, i, mid);
        max_r = find_max(arr, mid + 1, j);
        return (max_l > max_r) ? max_l : max_r;
    }
}
