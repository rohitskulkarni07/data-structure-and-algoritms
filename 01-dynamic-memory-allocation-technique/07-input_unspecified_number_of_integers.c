/**
 * @file 07-input_unspecified_number_of_integers.c
 * @author rohit kulkarni
 * @brief allocation memory to dynamically increasing and decreasing pointer
 * @date 2022-04-24
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int *p = NULL;                   /* base address of dynamically resizable array*/
    unsigned long long int size = 0; /* size of array */

    int n;                    /* variable to store integer */
    int response;             /* variable for registering user's response */
    unsigned long long int i; /* counter */

    while (1)
    {
        puts("Do you further wish to enter and Integer: (Press 1 to continue, otherwise any key to quit)");
        scanf("%d", &response);

        if (response != 1)
        {
            break;
        }

        printf("Enter an Integer: ");
        scanf("%d", &n);
        p = (int *)realloc(p, (size + 1) * sizeof(int));
        assert(p != NULL);
        size = size + 1;
        p[size - 1] = n;
    }

    for (i = 0; i < size; i++)
    {
        printf("*p(p+%llu): %d\n", i, *(p + i));
    }

    free(p);
    p = NULL;

    exit(EXIT_SUCCESS);
}

/**
 * *** just for reference ***
 * 
 * %d -> for integer
 * %ld -> for long
 * %lld -> long long
 * 
 * %u unsigned int
 * %lu unsigned long int  
 * %llu unsigned long long int
 * 
 * %hd -> short int
 * %hd -> 1 byte signed integer
 * 
 * %hu -> unsigned short int
 * %hhu -> unsigned char
 * 
 */