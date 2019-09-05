#include<stdio.h>
#include<stdlib.h>

// Node of the linked list
typedef struct Node {
	int data;
	struct Node *link;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List {
	Node *head;
	int number_of_nodes;
} List;

// Initializes a linked list
List* list_initialize();

// Creates a node and stores the data
Node* create_node(int);

// Deletes the node at the given position
// Does not delete anything if position is out of range
void del_at_pos(int, List*);

// Displays the contents of the linked list in space seperated manner.
void display(List*);

// Inserts an element into an ordered linked list.
void insert_in_order(int, List*);

// Returns the index of the key in the linked list.
// Returns -1 if key not found
int find_key(int, List*);

// Destroy the list by freeing all the nodes.
void destroy_list(List*);

int main()
{
    int choice,element,position,index;

    // Initialize an empty list.
    List* sll = list_initialize();
    do
    {   
        scanf("%d", &choice);
        switch(choice)
        {
            // Delete at given position
            case 1:
            {        
                scanf("%d", &position);
                del_at_pos(position, sll);
            }
            break;
        
            // Insert element into the ordered list.
            case 2: 
            { 
                scanf("%d", &element);
                insert_in_order(element, sll);
            }
            break;
            
            // Display the list.
            case 3:
            {
                display(sll);
            }
            break;
            
            // Find the given key.
            case 4:
            {        
                scanf("%d", &element);
                index = find_key(element, sll);
                printf("%d\n",index);
            }
            break;
            
            default:
                break;
        }
    }
    while(choice != 0);

    destroy_list(sll);

    return 0;
}

List* list_initialize() //COMPLETED.
{
    List *newlist;
    newlist=(List*)malloc(sizeof(List));
    newlist->head=  NULL;
    newlist->number_of_nodes=0;
    return newlist;
    
}

Node* create_node(int data)//COMPLETED.
{
    Node *newlist;
    newlist= (Node*)malloc(sizeof(Node));
    newlist->data=data;
    newlist->link=NULL;
    return newlist;
    
}

void display(List* sll)
{
    Node *temp=sll->head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }printf("\n");
}

void del_at_pos(int position, List* sll) 
{
    Node* temp,*prev,*node;
    int i=1;
    temp=sll->head;
    if(sll->head==NULL)
    {
        return;
    }
    else if(position==1)
    {
        sll->head=temp->link;
        free(temp);
        return;
    }
    else
    {
        while(temp!=NULL&&i<position)
        {
            prev=temp;
            temp=temp->link;
            i+=1;
        }
        if(i==position&&temp!=NULL)
        {
            prev->link=temp->link;
            free(temp);
        }
        else
        {
            return;
        }
    }
    

}

void insert_in_order(int element, List* sll)
{
    Node* newNodeCreated=create_node(element);
    
    if(sll->head==NULL)
    {   
        sll->head=newNodeCreated;
    }
    
    else
    {
        
        Node* sllTemp;
        Node* prev;
        sllTemp=sll->head;
        prev=NULL;
    
        while(sllTemp!=NULL)
        {   
            if(sllTemp->data<element)
                break;
                
            prev=sllTemp;
            sllTemp=sllTemp->link;
        }
        if(prev==NULL)
        {
            sll->head=newNodeCreated;
            newNodeCreated->link=sllTemp;
            
        }
        else
        {
            prev->link=newNodeCreated;
            newNodeCreated->link=sllTemp;
        }
    }
    sll->number_of_nodes+=1;
}

int find_key(int key, List* sll)
{
    int i=1;
    Node* temp=sll->head;
    
    for(i=0;i<sll->number_of_nodes;temp=temp->link)
    {
        if(temp->data==key)
            return i;
        i++;
    }
    return -1;
}

void destroy_list(List* sll)
{
    free(sll->head);
    sll->head=NULL;
    sll->number_of_nodes=0;
}
