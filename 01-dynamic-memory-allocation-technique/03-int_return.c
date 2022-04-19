#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void create_int_1(int **, int);
void create_int_2(int **, int);

int main()
{
    int *ptr1 = 0;
    int *ptr2 = 0;

    create_int_1(&ptr1, 100);
    create_int_2(&ptr2, 200);

    printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);
}

void create_int_1(int **pp, int init_n)
{
    *pp = malloc(sizeof(int));
    assert(*pp!=NULL);

    **pp = init_n;
    
}

void create_int_2(int **pp, int init_n)
{
    int *p = 0;
    
    p = malloc(sizeof(int));
    assert(p!=NULL);

    *p = init_n;
    *pp = p;

}