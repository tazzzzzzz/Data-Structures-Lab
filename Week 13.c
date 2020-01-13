
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *table;
    int size;
} HashTable;

// Create a hash table of the required size
HashTable *create_table(int size);

// Search for an element in the hash table
// Return 1 if the element is present in the table
// Return 0 otherwise
int search(HashTable *htable, int element);

// Insert the element into the hash table
void insert(HashTable *htable, int element);

// Delete the element from the hash table if present
void delete (HashTable *htable, int element);

// Display all the hash table elements
void display_table(HashTable *htable);

// Destroy the hash table
void destroy_table(HashTable *htable);

int main()
{
    int size, choice, loop = 1;
    int element, find;
    scanf("%d", &size);
    HashTable *htable = create_table(size);
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Insert element
            scanf("%d", &element);
            insert(htable, element);
            break;

        case 2:
            // Delete element
            scanf("%d", &element);
            delete (htable, element);
            break;

        case 3:
            // Search element
            scanf("%d", &element);
            find = search(htable, element);
            if (find)
                printf("YES\n");
            else
                printf("NO\n");
            break;

        case 4:
            // Print all elements in the hash table
            display_table(htable);
            break;

        default:
            // Destroy tree and exit the loop
            destroy_table(htable);
            loop = 0;
            break;
        }
    }
}

HashTable *create_table(int size)
{
    HashTable *hash=(HashTable*)calloc(1,sizeof(HashTable));
    hash->table=(int*)calloc(size,sizeof(int));
    hash->size=size;
    for(int i=0;i<size;i++)
        hash->table[i]=-1;
    return(hash);
}

void insert(HashTable *htable, int element)
{
    int key=element%htable->size;
    int count=0;
    while(htable->table[key]!=-1 && count!=htable->size)
    {
        key=(key+1)%htable->size;
        count++;
    }
    if(count<htable->size)
    {
        htable->table[key]=element;
    }
}

int search(HashTable *htable, int element)
{
    int key=element%htable->size;
    int count=0;
    while(htable->table[key]!=element && count!=htable->size)
    {
        key=(key+1)%htable->size;
        count++;
    }
    if(count<htable->size)
    {
        return 1;
    }
    else
        return 0;
}

void delete (HashTable *htable, int element)
{
    int key=element%htable->size;
    int count=0;
    while(htable->table[key]!=element && count!=htable->size)
    {
        key=(key+1)%htable->size;
        count++;
    }
    if(count<htable->size)
    {
        htable->table[key]=-1;
    }
}

void display_table(HashTable *htable)
{
    for(int i=0;i<htable->size;i++)
        printf("%d ",htable->table[i]);
    printf("\n");
}

void destroy_table(HashTable *htable)
{
}