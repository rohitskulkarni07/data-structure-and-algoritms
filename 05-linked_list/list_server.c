/**
 * @file list_server.c
 * @author rohit kulkarni
 * @brief Implementation of auxilary routine for doubly circular linked list
 * @date 2022-06-04
 */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* list interface routines implementation */
list_t *create_list(void)
{
    list_t *p_list = NULL;
    p_list = get_node(-1);

    // to maintain circular property of list
    p_list->prev = p_list;
    p_list->next = p_list;

    return (p_list);
}

status_t insert_start(list_t *p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end(list_t *p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list);
    return (SUCCESS);
}

status_t insert_after(list_t *p_list, data_t e_data, data_t new_data)
{
    node_t *e_node = search_node(p_list, e_data);

    if (!e_node)
    {
        /* code */
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert(e_node, get_node(new_data), e_node->next);
    return (SUCCESS);
}

status_t insert_before(list_t *p_list, data_t e_data, data_t new_data)
{
    node_t *e_node = search_node(p_list, e_data);

    if (!e_node)
    {
        /* code */
        return (LIST_DATA_NOT_FOUND);
    }

    generic_insert(e_node->prev, get_node(new_data), e_node);
    return (SUCCESS);
}
status_t get_start(list_t *p_list, data_t *p_start_data)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->next->data;
    return (SUCCESS);
}
status_t get_end(list_t *p_list, data_t *p_start_data)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->prev->data;
    return (SUCCESS);
}

status_t pop_start(list_t *p_list, data_t *p_start_data)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->next->data;
    generic_delete(p_list->next);
    return (SUCCESS);
}

status_t pop_end(list_t *p_list, data_t *p_start_data)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list->prev->data;
    generic_delete(p_list->prev);
    return (SUCCESS);
}

status_t remove_start(list_t *p_list)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    generic_delete(p_list->next);
    return (SUCCESS);
}

status_t remove_end(list_t *p_list)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    generic_delete(p_list->prev);
    return (SUCCESS);
}

status_t remove_data(list_t *p_list, data_t r_data)
{
    if (is_empty == TRUE)
    {
        return (LIST_EMPTY);
    }
    node_t *p_remove_node = NULL;

    p_remove_node = search_node(p_list, r_data);
    generic_delete(p_remove_node);
    return (SUCCESS);
}

bool is_empty(list_t *p_list)
{
    return (p_list->prev == p_list && p_list->next == p_list);
}

bool find(list_t *p_list, data_t f_data)
{
    node_t *p_node = NULL;
    p_node = search_node(p_list, f_data);
    return (p_node != NULL);
}

void show(list_t *p_list, const char *msg)
{
    node_t *p_run = NULL;
    if (msg)
    {
        puts(msg);
    }
    printf("[START]<-->");
    for (p_run = p_list->next; p_run != NULL; p_run = p_run->next)
    {
        printf("[ %d ]<-->", p_run->data);
    }
    printf("[END]");
}

status_t destroy_list(list_t **pp_list)
{
    list_t *p_list = NULL;
    node_t *p_run = NULL;
    node_t *p_run_next = NULL;

    p_list = *pp_list;
    p_run = p_list->next;

    while (p_run != p_list)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_list);
    p_list = NULL;

    *pp_list = NULL;

    return (SUCCESS);
}

len_t get_length(list_t *p_list)
{
    node_t *p_run = NULL;
    len_t len = 0;
    for (p_run = p_list->next; p_run != NULL; p_run = p_run->next)
    {
        len += 1;
    }
    return (len);
}

list_t *concat_list_imm(list_t *p_list_1, list_t *p_list_2)
{
    list_t *concat_list = NULL;
    node_t *p_run = NULL;
    concat_list = create_list();

    for (p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next)
    {
        assert(insert_end(concat_list, p_run->data) == SUCCESS);
    }

    for (p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next)
    {
        assert(insert_end(concat_list, p_run->data) == SUCCESS);
    }
}

list_t *concat_list_m(list_t *p_list_1, list_t *p_list_2)
{
    if (!p_list_2)
    {
        return (p_list_1);
    }

    p_list_1->prev->next = p_list_2->next;
    p_list_2->next->prev = p_list_1->prev;
    p_list_1->prev = p_list_2->prev;
    p_list_2->prev->next = p_list_1;

    free(p_list_2);
}

/* list auxilary routines implementation */

static void generic_insert(list_t *p_beg, list_t *p_mid, list_t *p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

static void generic_delete(node_t *p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;
}
static node_t *search_node(list_t *p_list, data_t s_data)
{
    node_t *p_run = NULL;

    p_run = p_list->next;
    while (p_run != p_list)
    {
        /* code */
        if (p_run->data == s_data)
        {
            return (p_run);
        }
        p_run = p_run->next;
    }

    return (NULL);
}

static node_t *get_node(data_t new_data)
{
    node_t *p_new_node = NULL;
    p_new_node = (node_t *)calloc(1, sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->prev = NULL;
    p_new_node->next = NULL;

    return (p_new_node);
}

static void *xcalloc(size_t nr_elements, size_t size_per_element)
{
    void *p = NULL;

    p = calloc(nr_elements, size_per_element);
    if (!p)
    {
        fprintf(stderr, "calloc : fatal :  out of virtual memory");
        exit(EXIT_FAILURE);
    }
}
