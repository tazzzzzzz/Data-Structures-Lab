#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    int rightThread;
    int leftThread;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void tree_initialize(Tree *tree);
void tree_insert(Tree *tree, int data);

/* Finds the inorder successor and predecessor of the given node */
void inorder_successor(Node *ptr);
void inorder_predecessor(Node *ptr);

/* Prints all the elements of the tree in ascending and descending order respectively */
void print_ascending(Tree *tree);
void print_descending(Tree *tree);

void tree_destroy(Tree *tree);
/* Advisory: While some guarded discernment could perhaps lead you to
 * more efficient implementations, you are requested to provide suitable recursive
 * solutions for the following function declarations.
 */

int main()
{
    int choice, loop = 1;
    Tree my_tree;
    tree_initialize(&my_tree);
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int element;
            int data;
        case 1:
            /* Insert elements */
            scanf("%d", &element);
            tree_insert(&my_tree, element);
            break;
        case 2:
            /* Print elements in the ascending order */
            print_ascending(&my_tree);
            break;
        case 3:
            /* Print elements in the descending order */
            print_descending(&my_tree);
            break;
        default:
            tree_destroy(&my_tree);
            loop = 0;
            break;
        }
    }
    return 0;
}

void tree_initialize(Tree *tree)
{
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *ptr = tree->root;
    Node *par = NULL;
   
    while(ptr!=NULL)
    {
        par = ptr;
       
        if(data < ptr->data)
        {
            if(ptr->leftThread == 0)
                ptr = ptr ->left;
            else
                break;
        }
        else
        {
            if(ptr->rightThread == 0)
                ptr = ptr -> right;
            else
                break;
        }
    }
   
    Node *tmp = malloc(sizeof(Node));
    tmp->data = data;
    tmp->leftThread = 1;
    tmp->rightThread = 1;
   
    if(par == NULL)
    {
        tree->root = tmp;
        tmp->left = NULL;
        tmp->right = NULL;
    }
    else if(data < (par->data))
    {
        tmp->left = par->left;
        tmp->right = par;
        par->leftThread = 0;
        par->left = tmp;
    }
    else
    {
        tmp->left = par;
        tmp->right = par->right;
        par->rightThread = 0;
        par->right = tmp;
    }
}

void inorder_predecessor(Node *ptr)
{
    if(ptr)
    {
        if(!ptr->rightThread)
            inorder_predecessor(ptr->right);
       
        printf("%d ",ptr->data);
       
        if(!ptr->leftThread)
            inorder_predecessor(ptr->left);
    }
}

void inorder_successor(Node *ptr)
{
    if(ptr)
    {   if(!ptr->leftThread)
        inorder_successor(ptr->left);
       
        printf("%d ",ptr->data);
       
        if(!ptr->rightThread)
        inorder_successor(ptr->right);
    }
}

void print_ascending(Tree *tree)
{  
    if(tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    inorder_successor(tree->root);
    printf("\n");
}

void print_descending(Tree *tree)
{  
    if(tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    inorder_predecessor(tree->root);
    printf("\n");
}

void destroy(Node *r)
{
    if(r)
    {
        if(!r->leftThread)
            destroy(r->left);
        if(!r->rightThread)
            destroy(r->right);
           
        free(r);
        r=NULL;
       
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
    t->root = NULL;
}

