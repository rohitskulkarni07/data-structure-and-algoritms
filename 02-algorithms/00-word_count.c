/**
 * @file word_count.c
 * @author rohit kulkarni
 * @brief counting total words in string 
 * @date 2022-04-22
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#define OUT 0
#define IN 1

int word_count(char *str)
{
    int state = OUT;
    unsigned int wc = 0;

    for (int i = 0; i < strlen(str); i++)
    {

        /* if not space and state is OUT then set state to IN and increment word count */
        if (!isspace(str[i]) && state == OUT)
        {
            state = IN;
            wc++;
        }
        else if (state == IN && isspace(str[i]))
        {
            state = OUT;
        }
    }
    return wc;
}

int main(void) {
    
    // input string 
    char str[] = "    \t\t \n\n hello     \t\n my  name is            rohit";

    // print count
    printf("WC: %i\n", word_count(str));

}