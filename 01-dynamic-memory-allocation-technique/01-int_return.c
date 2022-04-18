#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *create_int(int int_n);

int main(void)
{
    int *p = NULL;

    p = create_int(100);
    printf("*p = %d\n", *p);

    free(p);
    p = 0;

    return (0);
}

int *create_int(int int_n)
{
    int* p_int = NULL;
    p_int = (int*) malloc (sizeof(int)); // p_int =  malloc (sizeof(int)) explicit type casting not needed
    assert(p_int!=NULL);
    *p_int = int_n;
    return (p_int);
    
}