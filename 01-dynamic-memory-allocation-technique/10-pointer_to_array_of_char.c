#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 5

int main(void)
{

    int i = 0;
    int n = 0;
    char **pp = NULL;
    pp = (char **)malloc(5 * sizeof(char *));
    assert(pp != NULL);

    for (i = 0; i < N; i++)
    {
        pp[i] = (char *)malloc(sizeof(char *));
        assert(pp[i] != NULL);
    }

    for (i = 0; i < N; i++)
    {
        (*pp)[i] = (i + 97);
    }

    for (i = 0; i < N; i++)
    {
        n = *(*pp + i);
        printf("%d = %c\n", i + 1, n);
    }

    for (i = 0; i < N; i++)
    {
        free(pp[i]);
        pp[i] = NULL;
    }

    free(pp);
    pp = NULL;

    exit(0);
}
