#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int N;  /* number of array elements */
int *g_ptr = NULL;


void print_array(int );

int main(void)
{
    printf("Enter the array size: ");
    scanf("%d", &N);

    g_ptr = (int *)malloc(sizeof(int) * N);
    assert(g_ptr!=NULL);
    for(int i = 0; i < N; i++) {
        *(g_ptr + i) = i+1;
    }
    print_array(0);

    free(g_ptr);
    g_ptr = NULL;
    
}

void print_array(int index) 
{
    if(index == N) 
    {
        return;
    }
    print_array(index+1);
    printf("g_ptr[%d] = %d\n", index, g_ptr[index]);
}
