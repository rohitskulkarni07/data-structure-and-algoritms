#ifndef _STACK_H
#define _STACK_H

#include "list.h"

/* symbolic constant */
#define STACK_EMPTY LIST_EMPTY

/* typedefs */
typedef list_t my_stack_t;

my_stack_t *create_stack();
status_t push(my_stack_t *p_stack, data_t new_data);
status_t top(my_stack_t *p_stack, data_t *p_top_data);
status_t pop(my_stack_t *p_stack, data_t *p_pop_data);
status_t is_stack_empty(my_stack_t *p_stack);
status_t destroy_stack(my_stack_t **pp_stack);

#endif /* _STACK_H */