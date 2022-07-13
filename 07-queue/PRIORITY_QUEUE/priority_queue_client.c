#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "priority_queue.h"

int main(void)
{
    priority_queue_t *p_priority_queue;
    data_t arr[] = {100, 40, 20, 10, 80, 90, 75, 52, 23};
    int i;
    data_t data;
    status_t ret_val;

    p_priority_queue = create_priority_queue();

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
    {
        assert(priority_enqueue(p_priority_queue, arr[i]) == SUCCESS);
    }

    while (is_priority_queue_empty(p_priority_queue) != TRUE)
    {
        data = -1;
        priority_dequeue_min(p_priority_queue, &data);
        printf("data = %d\n", data);
    }

    ret_val = destroy_priority_queue(&p_priority_queue);
    assert(ret_val == TRUE && p_priority_queue == NULL);

    puts("Successful Implementation");
    exit(EXIT_SUCCESS);
}