#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5

int main(void)
{

    int i = 0;
    int n = 0;
    int **pp = NULL;
    pp = (int **)malloc(5 * sizeof(int *));
    assert(pp != NULL);

    for (i = 0; i < N; i++)
    {
        pp[i] = (int *)malloc(sizeof(int *));
        assert(pp[i] != NULL);
    }

    for (i = 0; i < N; i++)
    {
        (*pp)[i] = (i + 1) * 123;
    }

    for(i =0; i< N;i++) {
        n = *(*pp+i);
        printf("%d = %d\n",i+1, n);
    }

    for(i = 0; i < N; i++) {
        free(pp[i]);
        pp[i] = NULL;
    }

    free(pp);
    pp = NULL;

    exit(0);
}
