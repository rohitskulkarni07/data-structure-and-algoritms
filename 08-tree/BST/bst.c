#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

#define TRUE    1
#define FALSE   0

typedef int status_t;

struct bst_node
{
    int data;
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst
{
    struct bst_node *p_root_node;
    unsigned long long int nr_elements;
};

int main(void)
{
    struct bst *p_bst = NULL;
    status_t status;
    int data[] = {100, 150, 75, 200, 125, 85, 50, 65, 130};
    int data_np = {-100, 2004, 3453, -45635, 3456, 36353};

    int i;
    int pred_data, succ_data;
    int min_data, max_data;

    p_bst = create_bst();
}

struct bst *create_bst(void)
{
    struct bst *p_bst = NULL;

    p_bst = (struct bst *)malloc(sizeof(struct bst));
    if (p_bst == NULL)
    {
        fprintf(stderr, "malloc: fatal : Out of virtual memory\n");
        exit(EXIT_FAILURE);
    }
    p_bst->p_root_node = NULL;
    p_bst->nr_elements = 0;

    return (p_bst);
}

struct bst_node *get_bst_node(int new_element)
{
    struct bst_node *p_new_node = NULL;

    p_new_node = (struct bst_node *)malloc(sizeof(struct bst_node));

    if (p_new_node == NULL)
    {
        fprintf(stderr, "malloc: fatal : Out of virtual memory");
        exit(SUCCESS);
    }

    p_new_node->data = new_element;
    p_new_node->left = NULL;
    p_new_node->right = NULL;
    p_new_node->parent = NULL;

    return (p_new_node);
}

status_t bst_insert(struct bst *p_bst, int new_element)
{
    struct bst_node *p_new_node = NULL;
    struct bst_node *p_run = NULL;

    p_new_node = get_bst_node(new_element);
    p_run = p_bst->p_root_node;

    if (p_run == NULL)
    {
        p_bst->p_root_node = p_new_node;
        p_bst->nr_elements += 1;
        return (SUCCESS);
    }

    while (1)
    {   
        if (new_element <= p_run->data)
        {
            if (p_run->left == NULL)
            {
                p_run->left = p_new_node;
                p_new_node->parent = p_run;
                break;
            }
            else
            {
                p_run = p_run->left;
            }
        }
        else
        {
            if (p_run->right == NULL)
            {
                p_run->right = p_new_node;
                p_new_node->parent = p_run;
                break;
            }
            else
            {
                p_run = p_run->right;
            }
        }
    }
    p_bst->nr_elements+=1;
    return(SUCCESS);
}