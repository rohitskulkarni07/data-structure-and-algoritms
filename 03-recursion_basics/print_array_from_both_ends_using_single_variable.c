#include <stdio.h>
#include <stdlib.h>

void print_array_both_from_ends(int *, int, int);

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int N = sizeof(arr) / sizeof(arr[0]);
    print_array_both_from_ends(arr, 0, N);
    return (0);
}

/*   
    |_________________________________________________________________________________
    | i = 0 N = 12
    |_________________________________________________________________________________
    | i = 0 | a[0]  == a[N-1] = a[N-i-1] = a[12-0-1] = a[11]
    | i = 1 | a[1]  == a[N-2] = a[N-i-1] = a[12-1-1] = a[10]
    | i = 2 | a[2]  == a[N-3] = a[N-i-1] = a[12-2-1] = a[9]
    | i = 3 | a[3]  == a[N-4] = a[N-i-1] = a[12-3-1] = a[8]
    | i = 4 | a[4]  == a[N-5] = a[N-i-1] = a[12-4-1] = a[7]
    | i = 5 | a[5]  == a[N-6] = a[N-i-1] = a[12-5-1] = a[6]
    |_________________________________________________________________________________
*/

void print_array_both_from_ends(int *arr, int i, int N)
{
    if (i < N-i-1)
    {
        printf("%d | %d |\n", arr[i], arr[N-1-i]);
        print_array_both_from_ends(arr, i + 1, N);
    }
    else if (i == N-i-1)
    {
        printf("%d |\n", arr[N-1-i]);
        print_array_both_from_ends(arr, i + 1, N);
    }
}
