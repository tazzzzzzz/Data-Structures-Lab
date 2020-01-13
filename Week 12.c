#include <stdlib.h>
#include <stdio.h>

typedef struct heap {
    int capacity;
    int size;
    int *elements;
} heap;

heap* heap_construct(int initial_capacity);
void  heap_destruct(heap* heap);

int  heap_get_capacity(heap *heap);
int  heap_get_size(heap *heap);

/* 
	insert data into heap 
	return 1 if inserted.
	return 0 if size > capacity

*/
int heap_insert(heap *heap, int data);

/*return the min value without deleting it*/
int  heap_get_min(heap *heap);

/*delete the min value in the heap*/
void heap_remove(heap *heap);

/*Print the values(data) in ascending order by deleting the min value node from the heap each time*/
void heap_print(heap *heap);

int main() {
	int choice, loop = 1;
	int initial_capacity = 0;
	scanf("%d", &initial_capacity);
	heap *my_heap = heap_construct(initial_capacity);
	while(loop) {
		scanf("%d", &choice);
		switch(choice) {
			int number_of_elements, element, index;
			int data;
			case 1:
				/* Insert elements */ 
					scanf("%d", &element);
					if(!heap_insert(my_heap, element))
						printf("OVERFLOW\n");
				break;
				
			case 2:
				/* Print elements in sorted order, and empties the heap. */
				heap_print(my_heap);		
				heap_destruct(my_heap);
				loop = 0;
				break;
			
			default: 
				heap_destruct(my_heap);
				loop = 0;
		}
	}
	return 0;
}

/* Write suitable implementations for the function declarations */

heap* heap_construct(int n)
{
    heap*tmp=malloc(sizeof(heap));
    tmp->capacity=n;
    tmp->size=0;
    tmp->elements=(int*)malloc(sizeof(int)*n);
    return tmp;
}

void heap_destruct(heap* tmp)
{
    free(tmp->elements);
    tmp->elements=NULL;
    tmp->capacity=0;
}

int heap_get_capacity(heap* tmp)
{
    return tmp->capacity;
}

int heap_get_size(heap* tmp)
{
    return tmp->size;
}

int heap_insert(heap* tmp,int data)
{
    if(tmp->capacity==tmp->size)
    {
        return 0;
    }
    if(tmp->size==0)
        tmp->elements[tmp->size]=data;
    
    else
    {
       int i=tmp->size-1;
       while(tmp->elements[i]>data)
       {
           tmp->elements[i+1]=tmp->elements[i];
           i--;
       }
       tmp->elements[i+1]=data;
       
    }
    tmp->size++;  
    return 1;
    

}

int heap_get_min(heap* tmp)
{
 if(tmp->size>0)
    return tmp->elements[0];
}

void heap_remove(heap* tmp)
{
    if(tmp->size>0)
    {
        int i;
        for(i=1;i<tmp->size-1;i++)
            tmp->elements[i-1]=tmp->elements[i];
        tmp->size-=1;
    }
    
    
}

void heap_print(heap *my_heap)
{
int i;
for(i=0;i<my_heap->size;i++)
    printf("%d\n",my_heap->elements[i]);

}