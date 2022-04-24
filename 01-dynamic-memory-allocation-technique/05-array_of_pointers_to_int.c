#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_data_through_array_of_pointers(void);

int main(void)
{

    puts("\nIn Function: main()");

    int n0, n1, n2, n3, n4;
    int *arr[5] = {&n0, &n1, &n2, &n3, &n4};

    int i;
    int n;
    int **pp = NULL;

    pp = arr;

    for (i = 0; i < 5; ++i)
    {
        *pp[i] = (i + 1) * 100;
    }

    for (i = 0; i < 5; ++i)
    {
        n = *(*pp + i);

        printf("n%d = %d\n", i, n);
    }

    pp = NULL;

    print_data_through_array_of_pointers();

    exit(EXIT_SUCCESS);
}

void print_data_through_array_of_pointers(void)
{
    int n0, n1, n2, n3, n4;
    int **pp;

    int size_of_array = 5;

    int i;
    int n;

    puts("\nIn Function: print_data_through_array_of_pointers()");

    pp = malloc(sizeof(int *) * size_of_array);

    assert(pp != NULL);

    pp[0] = &n0;
    pp[1] = &n1;
    pp[2] = &n2;
    pp[3] = &n3;
    pp[4] = &n4;

    for (i = 0; i < 5; ++i)
    {
        *pp[i] = (i + 1) * 100;
    }

    for (i = 0; i < 5; ++i)
    {
        n = *(*pp + i);
        printf("n%d = %d\n", i, n);
    }

    free(pp);
    pp = NULL;
}