#include <stdio.h>
#include <stdlib.h>

int binary_search(int *, int, int, int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int end_index = ((sizeof(arr) / sizeof(arr[0])) - 1);

    int to_find = 10;
    int index_of_element_to_be_found = binary_search(arr, 0, end_index, to_find);

    printf("Element (%d) found at index: %d\n", to_find, index_of_element_to_be_found);

    return (EXIT_SUCCESS);
}

int binary_search(int *arr, int start_index, int end_index, int key)
{
    int mid_index = (start_index + end_index) / 2;

    if (key == arr[mid_index])
    {
        return mid_index;
    }
    else if (key < arr[mid_index])
    {
        return binary_search(arr, start_index, mid_index, key);
    }
    else if (key > arr[mid_index])
    {
        return binary_search(arr, mid_index + 1, end_index, key);
    }
    return -1;
}
