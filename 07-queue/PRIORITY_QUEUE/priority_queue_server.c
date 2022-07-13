#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"

priority_queue_t *create_priority_queue(void)
{
    return create_list();
}

status_t priority_enqueue(priority_queue_t *p_priority_queue, data_t data)
{
    return insert_end(p_priority_queue, data);
}

status_t priority_dequeue_min(priority_queue_t *p_priority_queue, data_t *p_data)
{
    int current_min_data;
    node_t *p_run = NULL;
    node_t *p_min_data_node = NULL;

    if (is_priority_queue_empty(p_priority_queue) == TRUE)
    {
        return (LIST_EMPTY);
    }

    current_min_data = p_priority_queue->next->data;
    p_min_data_node = p_priority_queue->next;

    for (p_run = p_priority_queue->next;
         p_run != p_priority_queue;
         p_run = p_run->next)
    {
        if (p_run->data < current_min_data)
        {
            p_min_data_node = p_run;
            current_min_data = p_run->data;
        }
    }

    generic_delete(p_min_data_node);
    *p_data = current_min_data;
    return (SUCCESS);
}

status_t is_priority_queue_empty(priority_queue_t *p_priority_queue)
{
    return is_list_empty(p_priority_queue);
}

status_t destroy_priority_queue(priority_queue_t **pp_priority_queue)
{
    return destroy_list(pp_priority_queue);
}

list_t *create_list()
{
    node_t *p_list = get_node(-1);
    p_list->prev = p_list;
    p_list->next = p_list;

    return (p_list);
}

status_t insert_beg(list_t *p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next);
    return (SUCCESS);
}

status_t insert_end(list_t *p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list);
    return (SUCCESS);
}

status_t remove_beg(list_t *p_list, data_t *p_beg_data)
{
    if (is_priority_queue_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_beg_data = p_list->next->data;
    generic_delete(p_list->next);
    return (SUCCESS);
}

status_t remove_end(list_t *p_list, data_t *p_end_data)
{
    if (is_priority_queue_empty(p_list) == TRUE)
    {
        return (LIST_EMPTY);
    }
    *p_end_data = p_list->prev->data;
    generic_delete(p_list->prev);
    return (SUCCESS);
}

status_t is_list_empty(list_t *p_list)
{
    return (p_list->prev == p_list && p_list->next == p_list);
}

status_t destroy_list(list_t **pp_list)
{
    node_t *p_list = *pp_list;
    node_t *p_run = NULL;
    node_t *p_run_next = NULL;

    p_run = p_list->next;
    while (p_run != p_list)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }
    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);
}

void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

void generic_delete(node_t *p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
}

node_t *get_node(data_t data)
{
    node_t *p_new_node = NULL;
    p_new_node = (node_t *)xcalloc(1, sizeof(node_t));

    p_new_node->data = data;
    p_new_node->prev = NULL;
    p_new_node->next = NULL;
    return (p_new_node);
}

void *xcalloc(size_t nr_elements, size_t size_per_elements)
{
    void *p = NULL;
    p = calloc(nr_elements, size_per_elements);
    assert(p);

    return (p);
}
