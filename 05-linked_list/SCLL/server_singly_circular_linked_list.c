#include <stdio.h>
#include <stdlib.h>

#include "singly_circular_linked_list.h"

list_t *create_list(void)
{
    node_t *p_head_node = NULL;
    p_head_node = (node_t *)xmalloc(sizeof(node_t));
    p_head_node->data = 0;
    p_head_node->next = p_head_node;

    return (p_head_node);
}

status_t insert_start(list_t *p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end(list_t *p_list, data_t new_data)
{
    node_t *p_last_node = NULL;
    get_last_node(p_list, &p_last_node);
    generic_insert(p_last_node, get_node(new_data), p_last_node->next);
    return (SUCCESS);
}

status_t insert_after(list_t *p_list, data_t e_data, data_t new_data)
{
    node_t *p_existing_node = NULL;
    p_existing_node = search_node(p_list, e_data);
    if (p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    generic_insert(p_existing_node, get_node(new_data), p_existing_node->next);
    return (SUCCESS);
}

status_t insert_before(list_t *p_list, data_t e_data, data_t new_data)
{
    node_t *p_existing_node = NULL;
    node_t *p_prev_node = NULL;

    get_node_and_prev(p_list, e_data, &p_existing_node, &p_prev_node);

    if (p_existing_node == NULL)
    {
        return (LIST_DATA_NOT_FOUND);
    }
    generic_insert(p_prev_node, get_node(new_data), p_existing_node);
    return (SUCCESS);
}

status_t get_start(list_t *p_list, data_t *p_start_data)
{
    if (is_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->next->data;
    return (SUCCESS);
}

status_t get_end(list_t *p_list, data_t *p_end_data)
{
    node_t *p_last_node = NULL;
    if (is_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    get_last_node(p_list, &p_last_node);
    *p_end_data = p_last_node->data;
    return (SUCCESS);
}

status_t pop_start(list_t *p_list, data_t *p_start_data)
{
    if (is_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->next->data;
    generic_delete(p_list, p_list->next);
    return (SUCCESS);
}

status_t pop_end(list_t *p_list, data_t *p_end_data)
{
    node_t *p_last_node = NULL;
    node_t *p_last_node_prev = NULL;
    if (is_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    get_last_node_and_prev(p_list, &p_last_node, &p_last_node_prev);
    *p_end_data = p_last_node->data;
    generic_delete(p_last_node_prev, p_last_node);
    return (SUCCESS);
}

status_t remove_start(list_t *p_list)
{
    if (is_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    generic_delete(p_list, p_list->next);
    return (SUCCESS);
}
status_t remove_end(list_t *p_list)
{
    node_t *p_last_node = NULL;
    node_t *p_last_node_prev = NULL;

    if (is_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    get_last_node_and_prev(p_list, &p_last_node, &p_last_node_prev);
    generic_delete(p_last_node_prev, p_last_node);
    return (SUCCESS);
}
status_t remove_data(list_t *p_list, data_t r_data)
{
    node_t *p_data_node = NULL;
    node_t *p_data_node_prev = NULL;

    get_node_and_prev(p_list, r_data, &p_data_node, &p_data_node_prev);
    generic_delete(p_data_node_prev, p_data_node);
    return (SUCCESS);
}

len_t get_length(list_t *p_list)
{
    node_t *p_run = NULL;
    len_t len = 0;
    p_run = p_list->next;
    while (p_run != p_list)
    {
        ++len;
        p_run = p_run->next;
    }
    return (len);
}

bool is_empty(list_t *p_list)
{
    return (p_list->next == p_list);
}

bool is_member(list_t *p_list, data_t s_data)
{
    node_t *p_node = NULL;
    p_node = search_node(p_list, s_data);
    if (p_node == NULL)
    {
        return (FALSE);
    }

    return TRUE;
}

void show(list_t *p_list, const char *msg)
{
    list_t *p_run = NULL;

    if (msg)
    {
        puts(msg);
    }

    p_run = p_list->next;
    printf("[ START ]->");
    while (p_run != p_list)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    puts("[ END ]");
}

list_t *concat(list_t *p_list_1, list_t *p_list_2)
{
    list_t *p_new_list = NULL;
    node_t *p_run = NULL;

    p_new_list = create_list();

    for (p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next)
    {
        insert_end(p_new_list, p_run->data);
    }

    for (p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next)
    {
        insert_end(p_new_list, p_run->data);
    }
    return (p_new_list);
}

list_t *merge(list_t *p_list_1, list_t *p_list_2)
{
    node_t *p_run1 = NULL;
    node_t *p_run2 = NULL;
    list_t *p_merged_list = NULL;

    p_merged_list = create_list();
    p_run1 = p_list_1->next;
    p_run2 = p_list_2->next;

    while (TRUE)
    {
        if (p_run1 == p_list_1)
        {
            for (; p_run2 != p_list_2; p_run2 = p_run2->next)
            {
                insert_end(p_merged_list, p_run2->data);
            }
            break;
        }

        if (p_run2 == p_list_2)
        {

            for (; p_run1 != p_list_1; p_run1 = p_run1->next)
            {
                insert_end(p_merged_list, p_run1->data);
                p_run1 = p_run1->next;
            }
            break;
        }

        if (p_run1->data <= p_run2->data)
        {
            insert_end(p_merged_list, p_run1->data);
            p_run1 = p_run1->next;
        }
        else
        {
            insert_end(p_merged_list, p_run2->data);
            p_run2 = p_run2->next;
        }
    }

    return (p_merged_list);
}

list_t *get_reversed_list(list_t *p_list)
{
    list_t *p_reversed_list = NULL;
    node_t *p_run = NULL;

    p_reversed_list = create_list();
    for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
    {
        insert_start(p_reversed_list, p_run->data);
    }
    return (p_reversed_list);
}

status_t append(list_t *p_list_1, list_t *p_list_2)
{
    node_t *p_last_node_of_list_1 = NULL;
    node_t *p_last_node_of_list_2 = NULL;

    if (is_empty(p_list_2))
    {
        return LIST_EMPTY;
    }
    get_last_node(p_list_1, &p_last_node_of_list_1);
    get_last_node(p_list_2, &p_last_node_of_list_2);

    p_last_node_of_list_1->next = p_list_2->next;
    p_last_node_of_list_2->next = p_list_1;

    free(p_list_1);

    return (SUCCESS);
}

status_t reversed_list(list_t *p_list)
{
    node_t *p_run = NULL;
    node_t *p_run_next = NULL;

    if (p_list->next == p_list || p_list->next->next == p_list)
    {
        return (SUCCESS);
    }

    p_run = p_list->next->next;
    p_list->next->next = p_list;
    while (p_run != p_list)
    {
        p_run_next = p_run->next;
        generic_insert(p_list, p_run, p_list->next);
        p_run = p_run_next;
    }
    return (SUCCESS);
}

void to_array(list_t *p_list, data_t **pp_array, size_t *p_size)
{
    data_t *p_array = NULL;
    size_t size = 0;
    node_t *p_run = NULL;
    len_t len = 0;
    int i = 0;

    len = get_length(p_list);
    if (!len)
    {
        *pp_array = p_array;
        *p_size = size;
        return;
    }

    p_array = (data_t *)xmalloc(len * sizeof(data_t));

    for (p_run = p_list->next, i = 0; p_run != p_list; p_run = p_run->next, ++i)
    {
		size++;
        p_array[i] = p_run->data;
    }
    *pp_array = p_array;
    *p_size = size;
}

list_t *to_list(data_t *p_array, size_t size)
{
    list_t *p_list = NULL;
    size_t i;

    p_list = create_list();
    for (i = 0; i < size; ++i)
    {
        insert_end(p_list, p_array[i]);
    }
    return (p_list);
}

status_t destroy_list(list_t **pp_list)
{
    node_t *p_run = NULL;
    node_t *p_run_next = NULL;

    list_t *p_list = NULL;
    p_list = *pp_list;

    for (p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        free(p_run);
    }

    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);
}

static void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end)
{
    p_mid->next = p_end;
    p_beg->next = p_mid;
}

static void generic_delete(node_t *p_prev_node, node_t *p_delete_node)
{
    p_prev_node->next = p_delete_node->next;
    free(p_delete_node);
}

static node_t *search_node(list_t *p_list, data_t s_data)
{
    node_t *p_run = NULL;

    p_run = p_list->next;

    while (p_run != p_list)
    {
        if (p_run->data == s_data)
        {
            break;
        }
        p_run = p_run->next;
    }
    return (p_run);
}

static void get_last_node(list_t *p_list, node_t **pp_last_node)
{

    list_t *p_run = NULL;
    p_run = p_list;
    while (p_run->next != p_list)
    {
        /* code */
        p_run = p_run->next;
    }
    *pp_last_node = p_run;
}

static void get_last_node_and_prev(list_t *p_list, node_t **pp_node, node_t **pp_prev_node)
{
    node_t *p_run = NULL;
    node_t *p_run_prev = NULL;

    p_run = p_list;
    p_run_prev = NULL;

    while (p_run->next != p_list)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    *pp_node = p_run;
    *pp_prev_node = p_run_prev;
}

static void get_node_and_prev(list_t *p_list, data_t s_data, node_t **pp_node, node_t **pp_prev_node)
{
    node_t *p_run = NULL;
    node_t *p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;

    while (p_run != p_list)
    {
        if (p_run->data == s_data)
        {
            *pp_node = p_run;
            *pp_prev_node = p_run_prev;
            return;
        }
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    *pp_node = NULL;
    *pp_prev_node = NULL;
}

static node_t *get_node(data_t new_data)
{
    node_t *p_new_node = NULL;
    p_new_node = (node_t *)xmalloc(sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return (p_new_node);
}

static void *xmalloc(size_t nr_bytes)
{

    void *p = NULL;
    p = malloc(nr_bytes);

    if (p == NULL)
    {
        fprintf(stderr, "malloc: out of memory\n");
        exit(EXIT_FAILURE);
    }

    return (p);
}