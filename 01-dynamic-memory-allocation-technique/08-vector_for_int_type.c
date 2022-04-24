/**
 * @file 08-vector_for_int_type.c
 * @author rohit kulkarni
 * @brief implementation of c++ like vector<> data_type for integer in c
 * @date 2022-04-24
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCUSS 1

struct vector_int
{
    /* data */
    int *p_arr;
    unsigned long long int size;
};

struct vector_int *create_vector_int(void);
int append_int(struct vector_int *, int);
void show_vector(struct vector_int *, const char *);
void destroy_vector_of_int(struct vector_int **);

int main(void)
{
    // to store 3 vectors
    struct vector_int *p_vec_rem0 = NULL; // store elements which yields remainder 0 when divisible by 3
    struct vector_int *p_vec_rem1 = NULL; // store elements which yields remainder 1 when divisible by 3
    struct vector_int *p_vec_rem2 = NULL; // store elements which yields remainder 2 when divisible by 3

    struct vector_int *p_vec = NULL;

    int i;
    int n;
    int nr_total = 1000; // range of numbers to operate on

    p_vec_rem0 = create_vector_int();
    p_vec_rem1 = create_vector_int();
    p_vec_rem2 = create_vector_int();

    for (i = 0; i < nr_total; ++i)
    {
        n = rand();
        switch (n % 3)
        {
        case 0:
            p_vec = p_vec_rem0;
            break;

        case 1:
            p_vec = p_vec_rem1;
            break;

        case 2:
            p_vec = p_vec_rem2;
            break;
        }
        append_int(p_vec, n);
        p_vec = NULL;
    }

    // display vectors data
    show_vector(p_vec_rem0, "Divisible by 3");
    show_vector(p_vec_rem1, "Divisible by 3 remainder 1");
    show_vector(p_vec_rem2, "Divisible by 3 remainder 2");

    // display vectors sizes
    printf("nr_elements(p_vec_rem0): %llu\n", p_vec_rem0->size);
    printf("nr_elements(p_vec_rem1): %llu\n", p_vec_rem1->size);
    printf("nr_elements(p_vec_rem2): %llu\n", p_vec_rem2->size);

    // free the memory
    destroy_vector_of_int(&p_vec_rem0);
    destroy_vector_of_int(&p_vec_rem1);
    destroy_vector_of_int(&p_vec_rem2);

    assert(p_vec_rem0 == NULL && p_vec_rem1 == NULL && p_vec_rem2==NULL);

    exit(EXIT_SUCCESS);
}


struct vector_int *create_vector_int(void)
{

    struct vector_int *p_vec_int = NULL;
    p_vec_int = (struct vector_int *)malloc(sizeof(struct vector_int));
    assert(p_vec_int != NULL);

    p_vec_int->p_arr = NULL;
    p_vec_int->size = 0;

    return (p_vec_int);
}

int append_int(struct vector_int *p_vec_int, int new_int)
{

    p_vec_int->p_arr = (int *)realloc(p_vec_int->p_arr, ((p_vec_int->size) + 1) * sizeof(int));
    assert(p_vec_int->p_arr != NULL);
    p_vec_int->size += 1;
    p_vec_int->p_arr[p_vec_int->size - 1] = new_int;
    return SUCCUSS;
}

void show_vector(struct vector_int *p_vec_int, const char *msg)
{
    unsigned long long int i;

    if (p_vec_int != NULL)
    {
        puts(msg);
    }

    for (i = 0; i < p_vec_int->size; ++i)
    {
        printf("p_vec_int[%llu]: %d\n", i, p_vec_int->p_arr[i]);
    }
}
void destroy_vector_of_int(struct vector_int **pp_vec_int)
{

    struct vector_int *p_vec_int = *pp_vec_int;
    free(p_vec_int->p_arr);
    p_vec_int->p_arr = NULL;
    free(p_vec_int);
    *pp_vec_int = NULL;
}