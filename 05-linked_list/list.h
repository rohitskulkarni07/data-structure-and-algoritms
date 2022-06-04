/**
 * @file list.h
 * @author rohit kulkarni
 * @brief this header file consist of functions for doubly circular linked list which client would like
 * for more details see list_specification.txt
 * @date 2022-06-04
 */
#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>

/* Symbolic constant */
#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int data_t;
typedef int status_t;
typedef int len_t;

typedef struct node node_t;
typedef node_t list_t;

/**
 *
 *             +-------+------+-------+
 *      node   | *prev | data | *next |
 *             +-------+------+-------+
 */

struct node
{
    data_t data;
    struct node *prev;
    struct node *next;
};

/* Interface functions */
/**
 * @brief Create a list object
 * Create a new list of integer
 *
 * @return list_t* pointer newly created node
 */

list_t *create_list(void);

/**
 * @brief insert given data into given list at start position
 *
 * @param p_list head node of the list
 * @param new_data new data to insert
 * @return status_t successful or failure insertion status
 */

status_t insert_start(list_t *p_list, data_t new_data);

/**
 * @brief Insert given data into given list at end position
 *
 * @param p_list head node of the list
 * @param new_data new data to insert
 * @return status_t successful or failure insertion status
 */
status_t insert_end(list_t *p_list, data_t new_data);

/**
 * @brief Insert given data into given list after given existing data
 *
 * @param p_list head node of the list
 * @param e_data existing data
 * @param new_data new data to insert
 * @return status_t successful or failure insertion status
 */
status_t insert_after(list_t *p_list, data_t e_data, data_t new_data);

/**
 * @brief Insert given data into given list before given existing data
 *
 * @param p_list head node of the list
 * @param e_data existing data
 * @param new_data new data to insert
 * @return status_t successful or failure insertion status
 */
status_t insert_before(list_t *p_list, data_t new_data);

/**
 * @brief Get the start node data from list
 *
 * @param p_list head node of the list
 * @param p_start_data out parameter to store data
 * @return status_t success status
 */
status_t get_start(list_t *p_list, data_t *p_start_data);

/**
 * @brief Get the end node data from list
 *
 * @param p_list head node of the list
 * @param p_start_data out parameter to store data
 * @return status_t success status
 */
status_t get_end(list_t *p_list, data_t *p_start_data);

/**
 * @brief Get the start node data & remove from list
 *
 * @param p_list head node of the list
 * @param p_start_data out parameter to store data
 * @return status_t success status
 */
status_t pop_start(list_t *p_list, data_t *p_start_data);

/**
 * @brief Get the end node data & remove from list
 *
 * @param p_list head node of the list
 * @param p_start_data out parameter to store data
 * @return status_t success status
 */
status_t pop_end(list_t *p_list, data_t *p_start_data);

/**
 * @brief Remove the data at start from given list
 *
 * @param p_list head node of the list
 * @return status_t success status
 */
status_t remove_start(list_t *p_list);

/**
 * @brief Remove the data at end from given list
 *
 * @param p_list head node of the list
 * @return status_t success status
 */
status_t remove_end(list_t *p_list);

/**
 * @brief Remove given data from list
 *
 * @param p_list head node of the list
 * @param r_data data to be remove
 * @return status_t success status
 */
status_t remove_data(list_t *p_list, data_t r_data);

/**
 * @brief Check if list is empty or not
 *
 * @param p_list head node of the list
 * @return true if list is empty else false if list is not empty
 */
bool isEmpty(list_t *p_list);

/**
 * @brief Check if given data is available in list or not
 *
 * @param p_list head node of the list
 * @param f_data data to be find in given list
 * @return true if data is present in list else false
 */
bool find(list_t *p_list, data_t f_data);

/**
 * @brief Display all the available data in list
 *
 * @param p_list head of the list
 * @param msg msg to print at the time of displaying
 */
void show(list_t *p_list, const char *msg);

/**
 * @brief Get the length list
 *
 * @param p_list head of the list
 * @return len_t length of list/number of nodes in lists
 */
len_t get_length(list_t *p_list);

/**
 * @brief Destroy or Free the memory acquired by list
 *
 * @param pp_list address of head node of the list
 * @return status_t success status
 */
status_t destroy_list(list_t **pp_list);

/* concat immutable */
/**
 * @brief Concat 2 given list without creating new list
 *
 * @param p_list_1 list 1 to be concat
 * @param p_list_2 list 2 be concat with
 * @return list_t* pointer concat-ed list
 */
list_t *concat_list_imm(list_t *p_list_1, list_t p_list_2);
// void concat_list_imm(list_t* p_list_1, list_t p_list2, list_t **pp_list);

/* concat mutable */
/**
 * @brief Concat 2 given list by creating new list
 *
 * @param p_list_1 list 1 to be concat
 * @param p_list_2 list 2 be concat with
 * @return list_t* pointer concat-ed list
 */
list_t *concat_list_m(list_t *p_list_1, list_t p_list2);

/**
 * @brief Merge 2 sorted list
 *
 * @param p_list_1 list 1 to be concat
 * @param p_list_2 list 2 be concat with
 * @return list_t newly created pointer to list
 */
list_t merge_lists(list_t *p_list_1, list_t p_list_2);

/**
 * @brief Reverse the list (immutable version)
 *
 * @param p_list head node to list
 * @return pointer to the list
 */
list_t *get_reversed_list(list_t *p_list);

/**
 * @brief Reverse the list (mutable version)
 *
 * @param p_list head node to list
 * @return pointer to the list
 * @return status_t success status
 */
status_t reverse_list(list_t *p_list);

/* list auxilary functions */

/**
 * @brief Search data in given list
 *
 * @param p_list head node to list
 * @param s_data data in node to be search in list
 * @return node_t* pointer to node where data found
 */
static node_t *search_node(list_t *p_list, data_t s_data);

/**
 * @brief Get the node object
 *
 * @param new_data data to be inserted in node->data
 * @return node_t* pointer to newly created node
 */
static node_t *get_node(data_t new_data);

/**
 * @brief Insert new node at position
 *
 * @param p_beg start node after which new node to be inserted at
 * @param p_mid new node to insert
 * @param p_end end node before which new node to be inserted at
 */
static void generic_insert(list_t *p_beg, list_t *p_mid, list_t *p_end);

/* auxilary function */
void *xcalloc(size_t nr_elements, size_t size_per_element);

#endif