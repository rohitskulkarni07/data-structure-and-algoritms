#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5

int main(void)
{
    int **pp = NULL;
    int size_of_array = 5;
    int i = 0;
    int n;

    pp = malloc(size_of_array * sizeof(int *));
    assert(pp != NULL);

    for (i = 0; i < size_of_array; ++i)
    {
        *(pp + i) = (int *)malloc(sizeof(int *));
        assert(pp[i] != NULL);
    }

    for (i = 0; i < size_of_array; ++i)
    {
        (*pp)[i] = (i + 1) * 5000;
    }

    for (i = 0; i < size_of_array; ++i)
    {
        n = *(*pp + i);
        printf("n%d = %d\n", i, n);
    }

    for(i = 0; i < size_of_array; ++i)
    {
        free(pp[i]);
        pp[i] = NULL;
    }

    free(pp);
    pp = NULL;

    exit(EXIT_SUCCESS);
}