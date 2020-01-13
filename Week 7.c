#include <stdlib.h>
#include <stdio.h>

typedef struct node node;

struct node
{
    int data;
    node *link;
};

typedef struct list
{
    node *head;
    node *tail;
    int number_of_nodes;
}s_list;

typedef struct queue
{
    s_list *ptr_list;
}queue;

void list_initialize(s_list* list); // Initializes the head, tail and no of nodes of the list.
void list_insert_rear(s_list* list, int data); // Inserts element at the rear of the list.
void list_insert_front(s_list* list, int data); // Inserts element at the front of the list.
void list_delete_front(s_list *list); // Deletes element at the front of the list. No operation if list is empty.
void list_delete_rear(s_list* list); // Deletes element at the rear of the list. No operation if list is empty.
const int node_get_data(node* node_ptr);
void list_destroy(s_list* list);
void display(s_list* list); // Prints the list. Prints "Empty Queue" if list is empty.

void queue_initialize(queue* ptr_queue);
void queue_enqueue_rear(queue* ptr_queue, int data);
void queue_dequeue_front(queue* ptr_queue);
void queue_enqueue_front(queue* ptr_queue, int data);
void queue_dequeue_rear(queue* ptr_queue);
int queue_is_empty(queue* ptr_queue); // Returns a boolean value.
const int queue_peek(queue* ptr_queue); // Returns the element at the front.
void queue_destroy(queue* ptr_queue);
void print_queue(queue* ptr_queue);

int main()
    {
        queue queue;
        queue_initialize(&queue);
        int choice,element;
        int loop = 1;
        while(loop)
        {
            scanf("%d", &choice);
            switch(choice)
            {
                case 0:
                        scanf("%d", &element);
                        queue_enqueue_front(&queue, element);
                        break;
                        
                case 1:
                        scanf("%d", &element);
                        queue_enqueue_rear(&queue, element);
                        break;
                        
                case 2:
                        queue_dequeue_front(&queue);
                        break;
                        
                case 3:
                        queue_dequeue_rear(&queue);
                        break;
                        
                case 4:
                        if(queue_is_empty(&queue))
                        {
                            printf("Empty Queue\n");
                        }
                        else
                        {
                            printf("%d\n", queue_peek(&queue));
                        }
                        break;
    
                case 5:
                        print_queue(&queue);
                        break;
                        
                default:
                        queue_destroy(&queue);
                        loop = 0;
            }
    }
    return 0;
}

static node* create_node(int data, node* link)
{
    node* new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->link=NULL;
    return new_node;
}

void list_initialize(s_list* ptr_list)
{
    ptr_list->head=ptr_list->tail=NULL;
    ptr_list->number_of_nodes=0;
}

void list_insert_rear(s_list* ptr_list, int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=NULL;
    if (ptr_list->head==NULL)
    {
       ptr_list->head=temp;
       ptr_list->number_of_nodes++;
    }
    else
    {
       node *curr=ptr_list->head;
       while (curr->link!=NULL)
       {
           curr=curr->link;
       }
       curr->link=temp;
       ptr_list->number_of_nodes++;
    }
}

const int node_get_data(node *node_ptr)
{
    return node_ptr->data;
}

void list_delete_front(s_list* ptr_list)
{
    node* temp=ptr_list->head;
    if (temp==NULL)
    {
       return;
    }
    ptr_list->head=temp->link;
    free(temp);
    ptr_list->number_of_nodes--;
}

void list_delete_rear(s_list* ptr_list)
{
    node *t,*u=NULL;
    if (ptr_list->head!=NULL)
    {
       if (ptr_list->head->link==NULL)
       {
           t=ptr_list->head;
           ptr_list->head=NULL;
           free(t);
       }
       else
       {
           t=ptr_list->head;
           while (t->link!=NULL)
           {
               u=t;
               t=t->link;
           }
           u->link=NULL;
           free(t);
       }
    }
    ptr_list->number_of_nodes--;
}

void list_insert_front(s_list* ptr_list, int data)
{
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->link=ptr_list->head;
    ptr_list->head=temp;
    ptr_list->number_of_nodes++;
}

void display(s_list* ptr_list)
{
    if (ptr_list->head==NULL)
    {
       printf("Empty Queue");
    }
    else
    {
       node* curr=ptr_list->head;
       while (curr!=NULL)
       {
           printf("%d ",curr->data);
           curr=curr->link;
       }
    }
    printf("\n");
}

void list_destroy(s_list* ptr_list)
{
    node *t,*u=NULL;
    t=ptr_list->head;
    while (t!=NULL)
    {
       u=t;
       t=t->link;
       free(u);
    }
}

int queue_is_empty(queue* ptr)
{
    return ptr->ptr_list->head==NULL;
}

const int queue_peek(queue* ptr)
{
    return ptr->ptr_list->head->data;
}

void queue_initialize(queue* queue_list)
{
    list_initialize(queue_list->ptr_list);
}

void queue_enqueue_rear(queue* ptr,int data)
{
    list_insert_rear(ptr->ptr_list,data);
}

void queue_dequeue_front(queue* ptr)
{
    list_delete_front(ptr->ptr_list);
}

void queue_destroy(queue* ptr)
{
    list_destroy(ptr->ptr_list);
}

void queue_enqueue_front(queue* ptr, int data)
{
    list_insert_front(ptr->ptr_list,data);
}

void queue_dequeue_rear(queue* ptr)
{
    list_delete_rear(ptr->ptr_list);
}

void print_queue(queue* ptr)
{
    display(ptr->ptr_list);
}
	
	
	

