/**
 * @file my_wc.c
 * @author rohit kulkarni
 * @brief implement wc command in c
 * @date 2022-04-26
 */

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h> // for isspace()

#define SUCCESS 1

/* states for counting words */
#define OUT 0
#define IN 1

/* to store data from file */
struct vector_char
{
    /* data */
    char *line;
    unsigned long long int length;
};

/* functions prototypes */
void my_word_count(unsigned long long int *char_count, unsigned long long int *word_count, unsigned long long int *line_count, size_t *byte_count, const char *filename);
size_t get_filesize(FILE **fp);
struct vector_char *create_vector_char(void);
int append_char(struct vector_char *, char ch);
void destroy_vector_char(struct vector_char **);
int count_words(char *, unsigned long long int);

/**
 * @brief take number of files as input and perform wc on those
 * 
 * @param argc count of arguments
 * @param argv file names
 * @return int status
 */
int main(int argc, char *argv[])
{
    unsigned long long int char_count = 0;
    unsigned long long int word_count = 0;
    unsigned long long int line_count = 0;
    size_t byte_count = 0;

    unsigned long long int total_cc = 0;
    unsigned long long int total_wc = 0;
    unsigned long long int total_lc = 0;
    size_t total_bc = 0;

    // throws usage error
    if (argc < 2)
    {
        puts("Invalid Argument!");
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    puts("characters\twords\tlines\t\tbyte-size\tfilename");
    for (int i = 1; i < argc; ++i)
    {
        my_word_count(&char_count, &word_count, &line_count, &byte_count, argv[i]);
        printf("%10llu\t%5llu\t%5llu\t\t%9lu\t%-8s\n", char_count, word_count, line_count, byte_count, argv[i]);
        total_cc += char_count;
        total_wc += word_count;
        total_lc += line_count;
        total_bc += byte_count;
    }

    printf("%10llu\t%5llu\t%5llu\t\t%9lu\t%-8s\n", total_cc, total_wc, total_lc, total_bc, "total");

    return (EXIT_SUCCESS);
}

/**
 * @brief this will read the file & will call actual word count 
 * 
 * @param char_count {out parameter} number of charaters in file
 * @param word_count {out parameter} number of words in file
 * @param line_count {out parameter} number of lines in file
 * @param byte_count {out parameter} byte size of file
 * @param filename name of the file to read
 */
void my_word_count(unsigned long long int *char_count, unsigned long long int *word_count, unsigned long long int *line_count, size_t *byte_count, const char *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    assert(!(fp == NULL));

    *byte_count = get_filesize(&fp);

    struct vector_char *p_line_data = NULL;
    p_line_data = create_vector_char();

    char ch = '\0';

    *char_count = 0;
    *line_count = 0;
    *word_count = 0;

    while (!feof(fp))
    {
        ch = fgetc(fp);
        assert(SUCCESS == append_char(p_line_data, ch));
        if (ch == '\n')
        {
            *line_count += 1;
        }
    }
    *word_count = count_words(p_line_data->line, p_line_data->length);
    *char_count = p_line_data->length;

    destroy_vector_char(&p_line_data);

    fclose(fp);
    fp = NULL;
}
/**
 * @brief count the word from file
 * 
 * @param line contains string
 * @param length length of the string 
 * @return int number of total words present in line
 */
int count_words(char *line, unsigned long long int length)
{

    int state = OUT;
    int count = 0;

    for (int i = 0; i < length; ++i)
    {
        if (!isspace(line[i]) && state == OUT)
        {
            state = IN;
            count += 1;
        }
        else if (isspace(line[i]) && state == IN)
        {
            state = OUT;
        }
    }
    return (count);
}

/**
 * @brief Create a vector char object allocates memory to char vector
 * 
 * @return struct vector_char* address of newly created pointer to char vector
 */
struct vector_char *create_vector_char()
{

    struct vector_char *p_vec_char = NULL;
    p_vec_char = (struct vector_char *)malloc(sizeof(struct vector_char));

    assert(p_vec_char != NULL);

    p_vec_char->line = NULL;
    p_vec_char->length = 0;

    return (p_vec_char);
}

/**
 * @brief appends data into char vectors line array
 * 
 * @param p_line_data char* in which data to be store 
 * @param ch character to be append
 * @return int success 1
 */
int append_char(struct vector_char *p_line_data, char ch)
{
    p_line_data->line = (char *)realloc(p_line_data->line, ((p_line_data->length) + 1) * sizeof(char));
    assert(p_line_data->line != NULL);
    p_line_data->length += 1;
    p_line_data->line[p_line_data->length - 1] = ch;
    return (SUCCESS);
}
/**
 * @brief free memory to allocated vector
 * 
 * @param pp_vec_char memory location to be freed
 */

void destroy_vector_char(struct vector_char **pp_vec_char)
{
    if (pp_vec_char)
    {

        struct vector_char *p_vec_char = *pp_vec_char;
        free(p_vec_char->line);
        p_vec_char->line = NULL;
        free(p_vec_char);
        *pp_vec_char = NULL;
    }
    assert(*pp_vec_char == NULL);
}

/**
 * @brief Get the filesize object calculates the size
 * of given file
 * 
 * @param fp file to be read for calculating its size
 * @return size_t size of the file 
 */
size_t get_filesize(FILE **fp)
{
    FILE *new_fp = *fp;
    fseek(new_fp, 0L, SEEK_END);
    size_t fsize = ftell(new_fp);
    rewind(new_fp);
    return (fsize);
}

/**
 * @brief To run compile the source code
 * gcc -o my_wc my_wc.c
 */