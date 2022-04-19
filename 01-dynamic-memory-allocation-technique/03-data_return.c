#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#pragma pack(4)

struct Date
{
    /* data */
    int day;
    int month;
    int year;
};

void create_date(struct Date **pp_date, int init_day, int init_month, int init_year);
void create_date_alt(struct Date **pp_date, int init_day, int init_month, int init_year);

int main(void)
{

    struct Date *p_date = NULL;
    printf("Before create_date() the address in p_date = %llu\n", (unsigned long long int)p_date);

    create_date(&p_date, 19, 04, 2022);
    printf("After create_date() the address in p_date = %llu\n", (unsigned long long int)p_date);

    create_date_alt(&p_date, 1, 0, 2024);
    printf("Alternative create_date() the address in p_date = %llu\n", (unsigned long long int)p_date);

    free(p_date);
    p_date = NULL;

    return (0);
}

void create_date(struct Date **pp_date, int init_day, int init_month, int init_year)
{
    *pp_date = malloc(sizeof(struct Date));
    assert(*pp_date != NULL);

    (*pp_date)->day = init_day;
    (*pp_date)->month = init_month;
    (*pp_date)->year = init_year;
}

void create_date_alt(struct Date **pp_date, int init_day, int init_month, int init_year)
{
    struct Date *p = NULL;
    p = malloc(sizeof(struct Date));
    assert(p!=NULL);
    p->day = init_day;
    p->month = init_month;
    p->month = init_year;

    *pp_date = p;
}