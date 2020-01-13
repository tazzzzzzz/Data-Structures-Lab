//    
#include <stdio.h>
#include <stdlib.h>

// Node of the circulat linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Handle of the list.
// Head points to the first node in the list.
// Tail points to the last node in the list.
typedef struct List
{
    Node *head;
    Node *tail;
    int length;
} List;

// initializes a cirucular linked list
List* initialize_list();

// Creates a node and stores the data in it.
Node* create_node(int data);

// Inserts data at offset position pos. No operation is required if pos is out of range.
void position_insert(List* cll, int data, int pos);

// Deletes the node at position pos. No operation is required if pos is out of range.
void position_delete(List* cll, int pos);

// Print the data present in the safe node according to the josephus problem.
int josephus(List* cll,int k);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(List* cll);

// Deallocates resources held by the list
void destroy_list(List*);

int main()
{

    List* cll = initialize_list();
    int ele,choice,pos,k;
    
    do
    {
        scanf("%d",&choice);

        switch(choice)
        {
            // Insert at position;
            case 1:
                scanf("%d %d",&ele,&pos);
                position_insert(cll,ele,pos);
                break;

            // Delete at position
            case 2:
                scanf("%d",&pos);
                position_delete(cll, pos);
                break;

            // Josephus problem
            case 3:
                scanf("%d",&k);
                ele = josephus(cll,k);
                printf("%d\n",ele);
                break;

            // Print entire list
            case 4:
                display(cll);
                break;        
        }
    }
    while (choice != 0);

    destroy_list(cll);
    return 0;
}

List* initialize_list()
{
    List* cll = (List*)malloc(sizeof(List));
    cll->head = NULL;
    cll->tail = NULL;
    cll->length = 0;

    return cll;
}

Node* create_node(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    return node;
}

void position_insert(List* cll, int data, int pos)
{
    if(pos<0 || pos>cll->length) return;

    Node *temp = create_node(data);

    if(cll->length == 0)
    {
        cll->head = temp;
        cll->tail = temp;
        temp->next = temp;
    }
    else if(pos == 0 || pos == cll->length)
    {
        cll->tail->next = temp;
        temp->next = cll->head;
        if(pos == 0) cll->head = temp;
        else cll->tail = temp;
    }
    else
    {
        Node *p = cll->head;
        for(int i=0;i<pos-1;i++) p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
    cll->length++;
}


void position_delete(List* cll, int pos)
{
    if(pos<0 || pos>=cll->length) return;
    
    Node *temp = cll->head;
    if(pos == 0)
    { 
        cll->head = temp->next;
        free(temp);
    }
    else 
    {
        for(int i=0;i<pos-1;i++) temp = temp->next;

        Node* p = temp->next;
        temp->next = p->next;
        if(p == cll->tail) cll->tail = temp;
        free(p);
    }
    cll->length--;
}

int josephus(List* cll, int k)
{
    Node* temp = cll->head;
    Node* p = NULL;

    for(int i=0;i<k;i++) temp = temp->next;

    while (temp->next != temp)
    {
        p = temp->next;
        temp->next = p->next;
        free(p);
        temp = temp->next;
    }

    cll->head = temp;
    cll->tail = temp;
    cll->length = 1;

    return temp->data;
}

void display(List* cll)
{
    if(cll->length == 0)
        printf("EMPTY");
    else
    {
        Node* temp = cll->head;
        for(int i=0;i<cll->length;i++)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }    
    printf("\n");
}

void destroy_list(List* cll)
{
    Node *p = cll->head;
	Node *q = NULL;

    for(int i=0;i<cll->length;i++)
    {
		q = p;
		p = p->next;
		free(q);
	}
	
    free(cll);
}
