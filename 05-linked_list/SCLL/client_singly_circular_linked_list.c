#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "singly_circular_linked_list.h"

int main(void)
{

    list_t *p_list = NULL;
    data_t data = 0;
    status_t status;

    p_list = create_list();
    puts("\n* * * SINGLY CIRCULAR LINKED LIST * * *\n");
    show(p_list, "Empty list:");

    for (data = 0; data < 5; data++)
    {
        status = insert_start(p_list, data);
        assert(status);
    }
    show(p_list, "After insert_start: ");

    for (data = 5; data < 10; data++)
    {
        status = insert_end(p_list, data);
        assert(status);
    }
    show(p_list, "After insert_end: ");

    status = insert_after(p_list, 0, 100);
    assert(status);
    show(p_list, "After insert_after: ");

    status = insert_before(p_list, 0, 200);
    assert(status);
    show(p_list, "After insert_before: ");

    status = get_start(p_list, &data);
    assert(status);
    printf("Start data: [%d]\n", data);
    show(p_list, "After get_start: ");

    status = get_end(p_list, &data);
    assert(status);
    printf("End data: [%d]\n", data);
    show(p_list, "After get_end: ");

    status = pop_start(p_list, &data);
    assert(status);
    printf("Start data: [%d]\n", data);
    show(p_list, "After pop_start: ");

    status = pop_end(p_list, &data);
    assert(status);
    printf("End data: [%d]\n", data);
    show(p_list, "After pop_end: ");

    status = remove_start(p_list);
    assert(status);
    show(p_list, "After remove_start: ");

    status = remove_end(p_list);
    assert(status);
    show(p_list, "After remove_end: ");

    status = remove_data(p_list, 0);
    assert(status);
    show(p_list, "After remove_data: ");

    status = reversed_list(p_list);
    assert(status);
    show(p_list, "After reversed_list: ");

    while (is_empty(p_list))
    {
        status = remove_start(p_list);
        assert(status);
    }
    show(p_list, "Empty list:  ");

    p_list = create_list();

    show(p_list, "Before reversing in place 1:  ");
    status = reversed_list(p_list);
    assert(status);
    show(p_list, "After reversing in place 1:  ");

    insert_end(p_list, 100);
    show(p_list, "Before reversing in place 2:  ");
    status = reversed_list(p_list);
    assert(status);
    show(p_list, "After reversing in place 2:  ");

    insert_end(p_list, 200);
    show(p_list, "Before reversing in place 3:  ");
    status = reversed_list(p_list);
    assert(status);
    show(p_list, "After reversing in place 3:  ");
    
    for (data = 5; data < 10; data++)
    {
        status = insert_end(p_list, data);
        assert(status);
    }
    
    list_t *p_new_reversed_list = get_reversed_list(p_list);
    show(p_list, "p_list After after get_reversed_list:");
    show(p_new_reversed_list, "new_reversed_list After get_reversed_lis:");

    status = destroy_list(&p_list);
    assert(status == SUCCESS);

    list_t *p_list_1 = create_list();
    list_t *p_list_2 = create_list();
    list_t *p_concat_list = create_list();

    show(p_list_1, "Empty list 1:");
    show(p_list_2, "Empty list 2:");
    show(p_concat_list, "Empty concat list:");

    for (data = 0; data < 5; data++)
    {
        status = insert_start(p_list_1, data * 2);
        status = insert_end(p_list_2, data * 3);
        assert(status == SUCCESS);
    }

    show(p_list_1, "After insert_start list 1:");
    show(p_list_2, "After insert_end   list 2:");

    p_concat_list = concat(p_list_1, p_list_2);

    show(p_concat_list, "After concat concat list:");

    list_t *p_append_list = create_list();

    for (data = 0; data < 5; data++)
    {
        status = insert_start(p_append_list, data * 13);
        assert(status == SUCCESS);
    }
    show(p_append_list, "After insert_start append list:");

    status = append(p_concat_list, p_append_list);
    assert(status);
    
    show(p_concat_list, "After append concat_list");

    p_list_1 = create_list();
    p_list_2 = create_list();

    for (data = 0; data <= 5; data++)
    {
        status = insert_end(p_list_1, data);
        status = insert_end(p_list_2, data * 2);
        assert(status == SUCCESS);
    }
    list_t *p_new_merge_list = merge(p_list_1, p_list_2);

    show(p_new_merge_list, "After merge p_new_merge_list");
    data_t *p_array = NULL;
    size_t size = 0;

    to_array(p_new_merge_list, &p_array, &size);

    puts("after to_array: ");
    for(size_t i = 0; i< size; i++) 
    {
        printf("[%d] ",p_array[i]);
    }
    printf("\n");
    p_list = to_list(p_array, size);
    show(p_list, "After to_list");

    puts("Implementation Successful");
    return (EXIT_SUCCESS);
}