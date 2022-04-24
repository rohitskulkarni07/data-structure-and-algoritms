/**
 * @file dynamic_memory_techniques.c
 * @author rohit kulkarni
 * @brief demonstration for dynamic memory allocation technique for user defined and built-in data types
 * @date 2022-04-20
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> /* include the header <string.h> or explicitly provide a declaration for 'memset' */

struct point
{
    /* data */
    double x, y, z;
};

/* function prototypes */
void built_in_data_type(void);
void array_of_built_in_data_type(void);
void array_of_pointers_to_built_in_data_type(void);

void user_defined_data_type(void);
void array_of_user_defined_data_type(void);
void array_of_pointers_to_user_defined_data_type(void);

int main(void)
{
    built_in_data_type();
    array_of_built_in_data_type();
    array_of_pointers_to_built_in_data_type();

    user_defined_data_type();
    array_of_user_defined_data_type();
    array_of_pointers_to_user_defined_data_type();

    return (0);
}

void built_in_data_type(void)
{
    int *p = NULL; /* declare & init pointer */

    puts("\n*** built_in_data_type ***");

    p = (int *)malloc(sizeof(int)); /* allocate memory */
    assert(p != NULL);              /* check if dynamic memory allocation succeeded */
    memset(p, 0, sizeof(int));      /* set to zero */

    *p = 500;                /* write */
    printf("*p = %d\n", *p); /* read */

    free(p);  /* mark memory as free */
    p = NULL; /* make pointer NULL */
}

void array_of_built_in_data_type(void)
{
    /* declare and initialize variables */
    int *p = NULL;
    int a_size = 5;
    int i = 0;

    puts("\n*** array_of_built_in_data_type ***");

    p = (int *)malloc(a_size * sizeof(int)); /* allocate memory */
    assert(p != NULL);                       /* check if dynamic memory allocation succeeded */
    memset(p, 0, sizeof(int) * a_size);      /* set to zero*/

    /* write random elements */
    for (i = 0; i < a_size; ++i)
    {
        *(p + i) = (i + 1) * 10;
    }

    /* read */
    for (i = 0; i < a_size; ++i)
    {
        printf("p[%d] : %d\n", i, p[i]);
    }

    free(p);  /* mark memory as free */
    p = NULL; /* make pointer NULL */
}

void array_of_pointers_to_built_in_data_type(void)
{
    /* declare and initialize variables */
    int **pp = NULL;
    int a_size = 5;
    int i = 0;

    puts("\n*** array_of_pointers_to_built_in_data_type ***");

    pp = (int **)malloc(a_size * sizeof(int *)); /* allocate memory */
    assert(pp != NULL);                          /* check if dynamic memory allocation succeeded */
    memset(pp, 0, a_size * sizeof(int *));       /* set to zero*/

    /* allocate memory */
    for (i = 0; i < a_size; ++i)
    {
        pp[i] = (int *)malloc(sizeof(int));
        assert(pp[i] != NULL);
        *pp[i] = (i + 1) * 10; /* write random data */
    }

    /* read */
    for (i = 0; i < a_size; ++i)
    {
        printf("*pp[%d] : %d\n", i, *pp[i]);
    }

    /* mark memory as free and make pointer NULL */
    for (i = 0; i < a_size; ++i)
    {
        free(pp[i]);
        pp[i] = NULL;
    }

    free(pp);  /* mark memory as free */
    pp = NULL; /* make pointer NULL */
}

void user_defined_data_type(void)
{
    struct point *p_point = NULL; /* declare and initialize to NULL */
    puts("\n*** user_defined_data_type ***");

    p_point = (struct point *)malloc(sizeof(struct point)); /* allocate memory */
    assert(p_point != NULL);                                /* check if dynamic memory allocation succeeded */
    memset(p_point, 0, sizeof(struct point));               /* set to zero */

    /* write */
    p_point->x = 1.2;
    p_point->y = 3.4;
    p_point->z = 5.6;

    /* read */
    printf("p_point->x= %lf | p_point->y %lf | p_point->z %lf\n", p_point->x, p_point->y, p_point->z);

    free(p_point);  /* mark memory as free */
    p_point = NULL; /* make pointer NULL */
}

void array_of_user_defined_data_type(void)
{
    /* declare and initialize */
    struct point *p_point = NULL;
    int array_size = 5;
    int i = 0;

    puts("\n*** array_of_user_defined_data_type ***");

    p_point = (struct point *)malloc(sizeof(struct point) * array_size); /* allocate memory */
    assert(p_point != NULL);                                             /* check if dynamic memory allocation succeeded */
    memset(p_point, 0, sizeof(struct point) * array_size);               /* set to zero */

    /* write by pointer arithmetic */
    for (i = 0; i < array_size; i++)
    {
        (*(p_point + i)).x = 1.2 + i;
        (*(p_point + i)).y = 3.4 + i;
        (*(p_point + i)).z = 5.6 + i;
    }
    /* write by subscript */
    // for (i = 0; i < array_size; i++)
    // {
    //     p_point[i].x = 1.2 + i;
    //     p_point[i].y = 3.4 + i;
    //     p_point[i].z = 5.6 + i;
    // }

    /* read */
    for (i = 0; i < array_size; i++)
    {
        printf("p_point[%d].x = %.2lf | p_point[%d].y = %.2lf | p_point[%d].z = %.2lf\n", i, p_point[i].x, i, p_point[i].y, i, p_point[i].z);
    }

    free(p_point);  /* mark memory as free */
    p_point = NULL; /* make pointer NULL */
}

void array_of_pointers_to_user_defined_data_type(void)
{
    /* declare and initialize */
    struct point **pp_point = NULL;
    int a_size = 5;
    int i = 5;

    puts("\n*** array_of_pointers_to_user_defined_data_type ***");

    pp_point = (struct point **)malloc(a_size * sizeof(struct point *)); /* allocate memory */
    assert(pp_point);                                                    /* check if dynamic memory allocation succeeded */
    memset(pp_point, 0, a_size * sizeof(struct point *));                /* set data to zero */

    for (i = 0; i < a_size; i++)
    {
        /* allocate memory */
        pp_point[i] = (struct point *)malloc(sizeof(struct point));

        /* check if dynamic memory allocation succeeded */
        assert(pp_point[i] != NULL);

        /* write */
        pp_point[i]->x = 1.2 + i;
        pp_point[i]->y = 3.4 + i;
        pp_point[i]->z = 5.6 + i;
    }

    /* read */
    for (i = 0; i < a_size; i++)
    {
        printf("pp_point[%d]->x : %.2lf | pp_point[%d]->y : %.2lf | pp_point[%d]->z : %.2lf\n", i, pp_point[i]->x, i, pp_point[i]->y, i, pp_point[i]->z);
    }

    /* mark memory as free */
    for (i = 0; i < a_size; i++)
    {
        free(pp_point[i]);
        pp_point[i] = NULL;
    }

    free(pp_point);
    pp_point = NULL;
}
