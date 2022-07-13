#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS                 1
#define TRUE                    1
#define FALSE                   0
#define LIST_DATA_NOT_FOUND     2
#define LIST_EMPTY              3
#define QUEUE_EMPTY             LIST_EMPTY

typedef int data_t;
typedef int status_t;

typedef struct node node_t;
typedef node_t list_t;
typedef list_t priority_queue_t;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

priority_queue_t *create_priority_queue(void);
status_t priority_enqueue(priority_queue_t *p_priority_queue, data_t data);
status_t priority_dequeue_min(priority_queue_t *p_priority_queue, data_t *p_data);
status_t is_priority_queue_empty(priority_queue_t *p_priority_queue);
status_t destroy_priority_queue(priority_queue_t **pp_priority_queue);

list_t *create_list();
status_t insert_beg(list_t *p_list, data_t new_data);
status_t insert_end(list_t *p_list, data_t new_data);
status_t remove_beg(list_t *p_list, data_t *p_beg_data);
status_t remove_end(list_t *p_list, data_t *p_end_data);
status_t is_list_empty(list_t *p_list);
status_t destroy_list(list_t **pp_list);

void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end);
void generic_delete(node_t *p_delete_node);
node_t *get_node(data_t data);
void *xcalloc(size_t nr_elements, size_t size_per_elements);

#endif /* _PRIORITY_QUEUE_H */