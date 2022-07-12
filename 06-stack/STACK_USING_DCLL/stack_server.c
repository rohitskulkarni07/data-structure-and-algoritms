#include "stack.h"

my_stack_t *create_stack()
{
    return create_list();
}

status_t push(my_stack_t *p_stack, data_t new_data)
{
    return insert_end(p_stack, new_data);
}

status_t top(my_stack_t *p_stack, data_t *p_top_data)
{
    return get_end(p_stack, p_top_data);
}

status_t pop(my_stack_t *p_stack, data_t *p_pop_data)
{
    return pop_end(p_stack, p_pop_data);
}

status_t is_stack_empty(my_stack_t *p_stack)
{
    return is_empty(p_stack);
}

status_t destroy_stack(my_stack_t **pp_stack)
{
    return destroy_list(pp_stack);
}
