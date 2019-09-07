#include <stdio.h>
#include <stdlib.h>
#define debug printf("Here")

// Node of the linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct DLList
{
    Node *head;
    int number_of_nodes;
}DLList;

// initializes a linked list
DLList* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at the beginning of the DLList
void insert_back(DLList* dll, int data);

// Deletes the node at position pos. No operation if pos is out of range.
void delete_back(DLList* dll);

// Return index of key in the list(0-based). Return -1 if not found
void reverse_list(DLList* dll);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(DLList* dll);

// Deallocates resources held by the list
void destroy_list(DLList*);

int main()
{
    DLList* dll = initialize_list();
    int ele, choice;
    
    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at the end of the list
            case 1:
                scanf("%d", &ele);
                insert_back(dll, ele);
                break;

            // Delete at the end of the list
            case 2:
                delete_back(dll);
                break;

            // Search for element
            case 3:
                reverse_list(dll);
                break;

            // Print entire list
            case 4:
                display(dll);
                break;      
        }
    } while (choice != 0);

    destroy_list(dll);
    return 0;
}

DLList* initialize_list()
{
    DLList* newnode= (DLList*)malloc(sizeof(DLList));
    newnode->head=NULL;
    newnode->number_of_nodes=0;
    return newnode;
}

Node* create_node(int data)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}

void insert_back(DLList* dll, int data)
{
    Node* newnode = create_node(data);
    if(dll->head==NULL)
    {
        dll->head=newnode;
    }
    else
    {
        Node *temp=dll->head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
    }
    dll->number_of_nodes+=1;
}

void delete_back(DLList* dll)
{
    if(dll->head==NULL)
    {
        return;
    }
    else if(dll->head->next==NULL&&dll->head->prev==NULL)
    {
        free(dll->head);
        dll->head=NULL;
        dll->number_of_nodes-=1;
    }
    else
    {
        Node *temp=dll->head;
        Node *prev;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        free(temp);
        prev->next=NULL;
        dll->number_of_nodes-=1;
    }
    
}

void reverse_list(DLList* dll)
{
    if(dll->head==NULL)
    {
        return;
    }
    else
        {
        Node* temp = NULL;
        Node* current = dll->head;
        while(current!=NULL)
        {
            temp=current->prev;
            current->prev=current->next;
            current->next=temp;
            current=current->prev;
        }
        if(temp!=NULL)
        {
            dll->head=temp->prev;
        }
    }
}

void display(DLList* dll)
{
    if(dll->number_of_nodes==0)
    {
        printf("EMPTY\n");
        return;
    }
    else
    {
        Node* temp=dll->head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
       
}

void destroy_list(DLList* dll)
{
    Node *temp,*prev;
    temp=dll->head;
    while(temp!=NULL)
    {
        prev=temp;
        temp=temp->next;
        free(temp);
    }
    dll->head=NULL;
}
