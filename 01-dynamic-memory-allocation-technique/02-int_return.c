#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void create_int(int *p, int init_n);

int main(void)
{

    int n;
    int *ptr = 0;

    create_int(&n, 500);
    printf("n = %d\n", n);

    ptr = malloc(sizeof(int)); // implicit typecasting of void * -> int*
    if (ptr == 0)
    {
        puts("Error: Failed to allocate the memory");
        exit(EXIT_FAILURE);   // return failure and terminate
    }

    create_int(ptr, 1000);
    printf("*ptr = %d\n", *ptr);

    // free the allocated memory
    free(ptr);

    // erase the address
    ptr = NULL;

    // return success and exit
    exit(EXIT_SUCCESS);
}

void create_int(int* p, int init_p) {
    *p = init_p;
}