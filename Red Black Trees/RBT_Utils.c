#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include "RBT_Header.h"

tree_node *new_tree_node(int data)  //Initialize new node.
{
    tree_node *n = malloc(sizeof(tree_node));
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    n->data = data;
    n->color = Red;
    return n;
}

red_black_tree *new_red_black_tree()    //Initialize new Red-Black Tree.
{
    red_black_tree *t = malloc(sizeof(red_black_tree));
    tree_node *nil_node = malloc(sizeof(tree_node));
    nil_node->left = NULL;
    nil_node->right = NULL;
    nil_node->parent = NULL;
    nil_node->color = Black;
    nil_node->data = 0;
    t->NIL = nil_node;
    t->root = t->NIL;
    return t;
}

void left_rotate(red_black_tree *t, tree_node *x)
{
    tree_node *y = x->right;
    x->right = y->left;
    if (y->left != t->NIL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == t->NIL)    //x is root
    { 
        t->root = y;
    }

    else if (x == x->parent->left)  //x is left child
    { 
        x->parent->left = y;
    }

    else    //x is right child
    { 
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

void right_rotate(red_black_tree *t, tree_node *x)
{
    tree_node *y = x->left;
    x->left = y->right;
    if (y->right != t->NIL)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == t->NIL)    //x is root
    { 
        t->root = y;
    }
    else if (x == x->parent->right) //x is left child
    { 
        x->parent->right = y;
    }
    else
    { //x is right child
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void insertion_fixup(red_black_tree *t, tree_node *z)
{
    while (z->parent->color == Red)
    {
        if (z->parent == z->parent->parent->left)
        { //z.parent is the left child

            tree_node *y = z->parent->parent->right; //uncle of z

            if (y->color == Red)
            { //case 1
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }
            else
            { //case2 or case3
                if (z == z->parent->right)
                {                  //case2
                    z = z->parent; //marked z.parent as new z
                    left_rotate(t, z);
                }
                //case3
                z->parent->color = Black;       //made parent black
                z->parent->parent->color = Red; //made parent red
                right_rotate(t, z->parent->parent);
            }
        }
        else
        {                                           //z.parent is the right child
            tree_node *y = z->parent->parent->left; //uncle of z

            if (y->color == Red)
            {
                z->parent->color = Black;
                y->color = Black;
                z->parent->parent->color = Red;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent; //marked z.parent as new z
                    right_rotate(t, z);
                }
                z->parent->color = Black;       //made parent black
                z->parent->parent->color = Red; //made parent red
                left_rotate(t, z->parent->parent);
            }
        }
    }
    t->root->color = Black;
}

void insert(red_black_tree *t, int val)
{
    tree_node *z = new_tree_node(val);
    tree_node *y = t->NIL; //variable for the parent of the added node
    tree_node *temp = t->root;

    if (search(t, val))
    {
        printf("\nElement already present in the Red Black Tree!");
        return;
    }
    while (temp != t->NIL)
    {
        y = temp;
        if (z->data < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    z->parent = y;

    if (y == t->NIL)    //newly added node is root
    { 
        t->root = z;
    }
    else if (z->data < y->data) //data of child is less than its parent, left child
        y->left = z;
    else
        y->right = z;

    //NIL nodes for the new node
    z->right = t->NIL;
    z->left = t->NIL;

    //fixup the color integrity of the tree
    insertion_fixup(t, z);
}

void rb_transplant(red_black_tree *t, tree_node *u, tree_node *v)   
{
    if (u->parent == t->NIL)
        t->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

tree_node *minimum(red_black_tree *t, tree_node *x) //Minimum node
{
    while (x->left != t->NIL)
        x = x->left;
    return x;
}

void rb_delete_fixup(red_black_tree *t, tree_node *x)
{
    while (x != t->root && x->color == Black)
    {
        if (x == x->parent->left)
        {
            tree_node *w = x->parent->right;
            if (w->color == Red)
            {
                w->color = Black;
                x->parent->color = Red;
                left_rotate(t, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == Black && w->right->color == Black)
            {
                w->color = Red;
                x = x->parent;
            }
            else
            {
                if (w->right->color == Black)
                {
                    w->left->color = Black;
                    w->color = Red;
                    right_rotate(t, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->right->color = Black;
                left_rotate(t, x->parent);
                x = t->root;
            }
        }
        else
        {
            tree_node *w = x->parent->left;
            if (w->color == Red)
            {
                w->color = Black;
                x->parent->color = Red;
                right_rotate(t, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == Black && w->left->color == Black)
            {
                w->color = Red;
                x = x->parent;
            }
            else
            {
                if (w->left->color == Black)
                {
                    w->right->color = Black;
                    w->color = Red;
                    left_rotate(t, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = Black;
                w->left->color = Black;
                right_rotate(t, x->parent);
                x = t->root;
            }
        }
    }
    x->color = Black;
}

void rb_delete(red_black_tree *t, tree_node *z)
{

    tree_node *y = z;
    tree_node *x;
    enum COLOR y_orignal_color = y->color;
    if (z->left == t->NIL)
    {
        x = z->right;
        rb_transplant(t, z, z->right);
    }
    else if (z->right == t->NIL)
    {
        x = z->left;
        rb_transplant(t, z, z->left);
    }
    else
    {
        y = minimum(t, z->right);
        y_orignal_color = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = z;
        }
        else
        {
            rb_transplant(t, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_orignal_color == Black)
        rb_delete_fixup(t, x);
}

void inorder(red_black_tree *t, tree_node *n)
{
    if (n != t->NIL)
    {
        inorder(t, n->left);
        printf("%d : %d \n", n->data, n->color);
        inorder(t, n->right);
    }
}


void preorder(red_black_tree *t, tree_node *n)
{
    if (n != t->NIL)
    {
        printf("%d : %d \n", n->data, n->color);
        preorder(t, n->left);
        preorder(t, n->right);
    }
}


void postorder(red_black_tree *t, tree_node *n)
{
    if (n != t->NIL)
    {
        postorder(t, n->left);
        postorder(t, n->right);
        printf("%d : %d \n", n->data, n->color);
        
    }
}

int search(red_black_tree *t, int val)
{
    tree_node *temp = t->root;
    int diff;

    while (temp != NULL)
    {
        diff = val - temp->data;

        if (diff > 0)
        {
            temp = temp->right;
        }

        else if (diff < 0)
        {
            temp = temp->left;
        }

        else
        {
            return 1;
        }
    }
    return 0;
}

void delete (red_black_tree *t, int val)
{
    if (search(t, val))
    {
        int flag = 0;
        tree_node *temp = t->root;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                flag = 1;
                rb_delete(t, temp);
                return;
            }
            if (temp->left->data < val)
                temp = temp->right;
            else
            {
                temp = temp->left;
            }
        }
    }
    else
    {
        printf("\nInteger element not found in Tree.");
    }
    return;
}
