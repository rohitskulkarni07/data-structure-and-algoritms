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
        return(LIST_DATA_NOT_FOUND);
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
        return(LIST_DATA_NOT_FOUND);
    }

    generic_insert(e_node->prev, get_node(new_data), e_node);
    return (SUCCESS);
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
/* list auxilary routines implementation */

static void generic_insert(list_t *p_beg, list_t *p_mid, list_t *p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
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
