#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include "RBT_Header.h"
int main()
{
    red_black_tree *t = new_red_black_tree();
    int choice, val, traversal, fl = 0;
    while (1)
    {
        printf("\nRed Black Tree. \n\nEnter your choice :\n1: Insert  \n2: Delete  \n3: Traversal  \n4: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {

            case 1:
                printf("\nEnter the integer element you want to insert into the Red Black Tree : ");
                scanf("%d", &val);
                insert(t, val);
                break;

            case 2:
                printf("\nEnter the integer element you want to delete from the Red Black Tree : ");
                scanf("%d", &val);
                delete (t, val);
                break;

            case 3: printf("\nEnter traversal technique: \n1: Preorder\n2: Inorder\n3: Postorder\n");
                    scanf("%d",&traversal);
                    printf("\nNote: 0 represents Red colour, and 1 represents Black colour.");
                    switch(traversal)
                    {
                        case 1: printf("\nPreorder traversal.\n");
                                preorder(t, t->root);
                                break;
                        
                        case 2: printf("\nInorder traversal.\n");
                                inorder(t, t->root);
                                break;
                        
                        case 3: printf("\nPostorder traversal.\n");
                                postorder(t, t->root);
                                break;
                        
                        default:printf("\nInvalid Input! Try again.\n");
                                break;
                    }
                    break;

            case 4:
                fl = 1;
                break;

            default:
                printf("\nInvalid Choice! Try entering a valid choice!\n");
        }
        printf("\n\n");
        if (fl == 1)
        {
            break;
        }
    }
    return 0;
}