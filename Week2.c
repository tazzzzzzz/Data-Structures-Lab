#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *link;
} Node;

typedef struct List {
	Node* head;
	int number_of_nodes;
} List;

/* initializes a linked list */
List* list_initialize(); 

/* Inserts a new node with data at the beginning */
void list_insert_beginning(List* list, int data);

/* Removes the last node of the linked list */
void list_delete_rear(List* list); 

/* Print the contents of a list */
void list_print(List* list); 

/* deallocates resources held by the list */
void list_destroy(List* list); 

int main() {
	int choice;
	List *list = list_initialize();
	do {
		scanf("%d", &choice);
		switch(choice) {
			int element;
			case 1:
				/* Insert an element at beginning of the list */ 
					scanf("%d", &element);
					list_insert_beginning(list, element);
					break;
			case 2:
				/* Remove rear elements */ 
					list_delete_rear(list);
					break;
			case 3:
				/* Print list contents */ 
				list_print(list);
				break;
			default: 
				list_destroy(list);
				break;
		}
	} while(choice >= 1 && choice < 4);
	
	return 0;
}
//DO NOT MODIFY THE ABOVE CODE.
//WRITE YOUR CODE BELOW.

List* list_initialize()
{
    List *l1 = (List*)malloc(sizeof(List));
    l1->head=NULL;
    l1->number_of_nodes=0;
    return l1;
}
void list_insert_beginning(List* list, int data)
{
    Node* element=(Node*)malloc(sizeof(Node));
    element->data=data;
    element->link=NULL;
    if(list->head==NULL)
    {
        list->head=element;
        list->number_of_nodes=list->number_of_nodes+1;
    }
    else
    {
        element->link=list->head;
        list->head=element;
        list->number_of_nodes=list->number_of_nodes+1;
        /*
        Node *current;
        current=list->head;
        list->head=element;
        element->link=current;
        list->number_of_nodes=list->number_of_nodes+1;
        */
    }
}
void list_delete_rear(List* list)
{
    Node* current = (Node*)malloc(sizeof(Node));
    current=list->head;
    if(list->number_of_nodes==0)
    {
        return;
    }   
    else if(current->link==NULL)
    {
        list->head=NULL;
        list->number_of_nodes=list->number_of_nodes-1;
    }
    else
    {
        while(current->link->link!=NULL)
        {
            current=current->link;
        }
        current->link=NULL;
        list->number_of_nodes=list->number_of_nodes-1;
    }
}   


void list_print(List *list)
{
    Node* current = (Node*)malloc(sizeof(Node));
    current=list->head;
    if(list->number_of_nodes==0)
    {
        printf("EMPTY \n");
        return;
    }
    else
    {
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current=current->link;
        }
        printf("\n");
    }
    
}


void list_destroy(List *list)
{
       free(list);
}












