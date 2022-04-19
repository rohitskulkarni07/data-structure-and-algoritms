#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Date
{
    /* data */
    int day;
    int month;
    int year;
};

/* The first formal parameter is an 'in' parameter */
void create_date(struct Date *p_date, int init_day, int init_month, int init_year);

int main(void)
{
    struct Date cpa_birth_date;
    struct Date *p_my_birth_date = NULL;
    struct Date *p_test_date = NULL;

    create_date(&cpa_birth_date, 1, 12, 2009);
    printf("CPA Birthdate: %d-%d-%d\n", cpa_birth_date.day, cpa_birth_date.month, cpa_birth_date.year);

    
    // allocate
    p_my_birth_date = malloc(sizeof(struct Date));
    
    // check
    assert(p_my_birth_date != NULL);

    // use
    create_date(p_my_birth_date, 7, 9, 1997);
    printf("My Birthdate: %d-%d-%d\n", p_my_birth_date->day, p_my_birth_date->month, p_my_birth_date->year);

    // free
    free(p_my_birth_date);

    // null
    p_my_birth_date = NULL;

    return (0);
}

void create_date(struct Date *p_date, int init_day, int init_month, int init_year)
{
    p_date->day = init_day;
    p_date->month = init_month;
    p_date->year = init_year;
}
