/**
 * @file word_search_in_file.c
 * @author rohit kulkarni
 * @brief this programs searches word in given file
 * @date 2022-05-12
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct FILEINFO
{
    /* data */
    char *line;
    unsigned int fileSize;
};

#define TRUE 1
#define FALSE 0

struct FILEINFO *readFile(const char *);
unsigned int getFileSize(FILE *fp);

struct FILEINFO *create_vector_char(void);
int append_char(struct FILEINFO *, char ch);
void destroy_vector_char(struct FILEINFO **);
int word_search();

int main(int argc, char *argv[])
{
    int files_count;
    if (argc < 2)
    {
        printf("Usage Error!\nCorrect Usage %s filename.ext\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("total files as input: %d\n", argc);

    struct FILEINFO *p_fileinfo[argc - 1];

    for (int i = 1; i < argc; i++)
    {
        p_fileinfo[i - 1] = readFile(argv[i]);
        printf("%d", p_fileinfo[i - 1]->fileSize);
    }

    char input = 'Y';
    char *word_to_search;
    char *word_to_compare;

    int j = 0;
    while (input == 'y' || input == 'Y')
    {
        /* code */
        printf("Enter word to search: ");
        scanf("%s", word_to_search);
        printf("%s", word_to_search);

        int length_of_word_to_search = strlen(word_to_search);

        printf("\n%d\n", strcmp(word_to_search, p_fileinfo[j]->line));

        printf("Do you want to continue? if yes enter Y else N\n");
    }

    exit(EXIT_SUCCESS);
}

struct FILEINFO *readFile(const char *filename)
{
    char ch;
    FILE *fp = NULL;
    fp = fopen(filename, "r+");
    assert(!(fp == NULL));

    struct FILEINFO *fileInfo = NULL;
    fileInfo = create_vector_char();

    while (!feof(fp))
    {
        ch = fgetc(fp);
        append_char(fileInfo, ch);
    }

    return (fileInfo);
}

struct FILEINFO *create_vector_char(void)
{
    struct FILEINFO *fileInfo = NULL;

    fileInfo = (struct FILEINFO *)malloc(sizeof(struct FILEINFO));
    assert(!(fileInfo == NULL));

    fileInfo->fileSize = 0;
    fileInfo->line = 0;

    return fileInfo;
}

int append_char(struct FILEINFO *p_file_info, char ch)
{
    p_file_info->line = (char *)realloc(p_file_info->line, sizeof(char) * (p_file_info->fileSize + 1));
    assert(!(p_file_info == NULL));

    p_file_info->fileSize += 1;
    p_file_info->line[p_file_info->fileSize - 1] = ch;

    return TRUE;
}