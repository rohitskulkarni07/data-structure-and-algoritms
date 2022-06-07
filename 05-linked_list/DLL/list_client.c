#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main(void)
{
    list_t *p_list = NULL;
    list_t *p_reversed_list = NULL;
    list_t *p_list_1 = NULL;
    list_t *p_list_2 = NULL;
    list_t *p_concat_list = NULL;
    list_t *p_merged_list = NULL;

    data_t data;
    status_t status;

    p_list = create_list();
    assert(p_list);

    show(p_list, "\nAfter Creation: ");

    assert(is_empty(p_list) == TRUE);
    assert(get_length(p_list) == 0);
    assert(get_start(p_list, &data) == LIST_EMPTY);
    assert(get_end(p_list, &data) == LIST_EMPTY);
    assert(pop_start(p_list, &data) == LIST_EMPTY);
    assert(pop_end(p_list, &data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);

    for (data = 0; data < 5; ++data)
    {
        assert(insert_start(p_list, data) == SUCCESS);
    }
    show(p_list, "After insert_start: ");

    for (data = 5; data < 10; ++data)
    {
        assert(insert_end(p_list, data) == SUCCESS);
    }
    show(p_list, "After insert_end: ");

    assert(insert_after(p_list, -10, 100) == LIST_DATA_NOT_FOUND);
    assert(insert_before(p_list, 300, 200) == LIST_DATA_NOT_FOUND);

    assert(insert_after(p_list, 0, 100) == SUCCESS);
    show(p_list, "After insert_after: ");

    assert(insert_before(p_list, 0, 200) == SUCCESS);
    show(p_list, "After insert_before: ");

    assert(get_length(p_list) > 0);
    data = -1;
    assert(get_start(p_list, &data) == SUCCESS);
    printf("\nStart Data: %d\n", data);
    show(p_list, "After get_start: ");

    data = -1;
    assert(get_end(p_list, &data) == SUCCESS);
    printf("\nEnd Data: %d\n", data);
    show(p_list, "After get_end: ");

    data = -1;
    assert(pop_start(p_list, &data) == SUCCESS);
    printf("\nPop Start Data: %d\n", data);
    show(p_list, "After pop_start ");

    data = -1;
    assert(pop_end(p_list, &data) == SUCCESS);
    printf("\nPop End Data: %d\n", data);
    show(p_list, "After pop_end: ");

    assert(remove_start(p_list) == SUCCESS);
    show(p_list, "After remove_start: ");

    assert(remove_end(p_list) == SUCCESS);
    show(p_list, "After remove_end: ");

    assert(remove_data(p_list, -10) == LIST_DATA_NOT_FOUND);
    assert(remove_data(p_list, 0) == SUCCESS);
    show(p_list, "After remove_data: ");

    printf("\nLength = %d\n", get_length(p_list));
    assert(is_empty(p_list) == FALSE);

    if (find(p_list, -10) == FALSE)
    {
        puts("\n-10 is not present in list\n");
    }

    if (find(p_list, 2) == TRUE)
    {
        puts("\n2 is present in list\n");
    }

    show(p_list, "list before immutable reversal!");
    p_reversed_list = get_reversed_list(p_list);
    show(p_reversed_list, "showing reversed version of p_list after immutable reversal!");
    show(p_list, "showing p_list after get_reversed_list: p_list should be same before and after reversal");
    assert(destroy_list(&p_reversed_list) == SUCCESS && p_reversed_list == NULL);

    show(p_list, "list before mutable reversal!");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "list after mutable reversal!");

    while (is_empty(p_list) != TRUE)
    {
        assert(remove_end(p_list) == SUCCESS);
    }
    assert(is_empty(p_list) == TRUE);

    show(p_list, "List should be empty!");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "list after mutable reversal should also be empty!");

    assert(insert_end(p_list, 100) == SUCCESS);
    show(p_list, "List should contain 1 element");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "Reversed after inserting 1 element in same empty list");
    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL);

    puts("\nTesting Inter-list Routines\n");

    p_list_1 = create_list();
    p_list_2 = create_list();
    assert(is_empty(p_list_1) && is_empty(p_list_2));
    p_merged_list = merge_lists(p_list_1, p_list_2);
    printf("\nHERE\n");
    assert(is_empty(p_merged_list) == TRUE);
    assert(destroy_list(&p_merged_list) == SUCCESS && p_merged_list == NULL);

    for (data = 5; data <= 95; data += 10)
    {
        assert(insert_end(p_list_1, data) == SUCCESS);
    }

    for (data = 10; data <= 60; data += 10)
    {
        assert(insert_end(p_list_2, data) == SUCCESS);
    }


    show(p_list_1, "p_list_1: Before immutable concat");
    show(p_list_2, "p_list_2: Before immutable concat");
    p_concat_list = concat_list_imm(p_list_1, p_list_2);
    show(p_concat_list, "p_concat_list: after concat");
    show(p_list_1, "p_list_1: After immutable concat");
    show(p_list_2, "p_list_2: After immutable concat");

    p_merged_list = merge_lists(p_list_1, p_list_2);
    show(p_merged_list, "p_merge_list: After merge");
    show(p_list_1, "p_list_1: After merge");
    show(p_list_2, "p_list_2: After merge");

    puts("p_list_1 and p_list_2 : After merge = before concat_list_m");
    assert(concat_list_m(p_list_1, p_list_2) == SUCCESS);
    p_list_2 = NULL;
    show(p_list_1, "p_list_1: After concat_list_m");

    assert(destroy_list(&p_concat_list) == SUCCESS && p_concat_list == NULL);
    assert(destroy_list(&p_merged_list) == SUCCESS && p_merged_list == NULL);
    assert(destroy_list(&p_list_1) == SUCCESS && p_list_1 == NULL);
    puts("Implementation successful!\n");

    return (EXIT_SUCCESS);
}