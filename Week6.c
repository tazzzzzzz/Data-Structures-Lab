#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure using an array
typedef struct Stack {
	int* arr;
	int top;
} Stack;

// Initialise a Stack of given size
Stack* stack_initialize(int);

int source_integrity(char *source_infix);

// Push an element onto the Stack
void stack_push(Stack*, int);

// Pop an element from the Stack. Do not return the element
void stack_pop(Stack*);

// Check if the Stack is empty
int stack_is_empty(Stack*);

// Return the top element of the Stack
int stack_peek(Stack*);

// Free the resources held by the Stack
void stack_destroy(Stack*);

// Convert an infix expression to postfix expression
void convert_infix_to_postfix(const char*, char*);

int prec(char);

int main() {
	char source_infix[2000];
	char target_postfix[2000];
	int number_of_inputs = 0;
	scanf("%d", &number_of_inputs);
	for(int counter = 0; counter < number_of_inputs; ++ counter) {
		scanf("%s", source_infix);
		convert_infix_to_postfix(source_infix, target_postfix);
		printf("%s\n", target_postfix);
	}
	return 0;
}

Stack* stack_initialize(int size)
{
    Stack* newstack = (Stack*)malloc(sizeof(Stack));
    newstack->top = -1;
    newstack->arr = (int*)malloc(sizeof(int)*size);
    return newstack;
}

void stack_push(Stack *ptr_stack, int key) 
{
    ptr_stack->arr[++ptr_stack->top] = key;
}

void stack_pop(Stack *ptr_stack)
{
    ptr_stack->arr[ptr_stack->top--];
}

int stack_is_empty(Stack *ptr_stack)
{
    return(ptr_stack->top==-1);
}

int stack_peek(Stack *ptr_stack) 
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(Stack *ptr_stack) 
{
    free(ptr_stack->arr);
    free(ptr_stack);
    ptr_stack=NULL;
}

int prec(char ch)
{
    if(ch == '/' || ch == '*') return 2;
    if(ch == '+' || ch == '-') return 1;
    return 0;
}

int source_integrity(char *source_infix)
{
    int i;
    int integrity = 0;
    for(i=0;source_infix[i];i++)
    {
        if(source_infix[i] == '[' || source_infix[i] == '{' || source_infix[i] == '(')
            integrity+=1;
        else if(source_infix[i] == ']' || source_infix[i] == '}' || source_infix[i] == ')')
            integrity-=1;
    }
    return integrity;
    
}

void convert_infix_to_postfix(const char *source_infix, char *target_postfix)
{
    if(source_integrity(source_infix))
    {
        //printf("Incorrect Input");
        return;
    }
    
    Stack* stack_ptr = stack_initialize(strlen(source_infix));
    int i,k;
    for(i=0,k=-1;source_infix[i];i++)
    {
        //IF it is an operand
        if((source_infix[i]>='a' && source_infix[i]<='z')||(source_infix[i]>='A'&&source_infix[i]<='Z'))
        {
            target_postfix[++k]=source_infix[i];
        }
        
        //If it is an opening bracket
        else if(source_infix[i]=='('||source_infix[i]=='{'||source_infix[i]=='[')
        {
           stack_push(stack_ptr,source_infix[i]); 
        }
        
        //IF )
        else if(source_infix[i]==')')
        {
            while(!stack_is_empty(stack_ptr) && stack_peek(stack_ptr)!='(')
            {
                target_postfix[++k] = stack_peek(stack_ptr);
                stack_pop(stack_ptr);
            }
            if(stack_peek(stack_ptr)=='(') stack_pop(stack_ptr);
        }
        
        //IF ]
        else if(source_infix[i]==']')
        {
            while(!stack_is_empty(stack_ptr) && stack_peek(stack_ptr)!='[')
            {
                target_postfix[++k] = stack_peek(stack_ptr);
                stack_pop(stack_ptr);
            }
            if(stack_peek(stack_ptr)=='[') stack_pop(stack_ptr);
        }
        
        //IF )
        else if(source_infix[i]=='}')
        {
            while(!stack_is_empty(stack_ptr) && stack_peek(stack_ptr)!='{')
            {
                target_postfix[++k] = stack_peek(stack_ptr);
                stack_pop(stack_ptr);
            }
            if(stack_peek(stack_ptr)=='{') stack_pop(stack_ptr);
        }
        
        //If an operator
        else
        {
            while(!stack_is_empty(stack_ptr)&&prec(source_infix[i])<=prec(stack_peek(stack_ptr)))
            {
                target_postfix[++k] = stack_peek(stack_ptr);
                stack_pop(stack_ptr);
            }
            stack_push(stack_ptr,source_infix[i]);
        }
    }
    while(!stack_is_empty(stack_ptr))
    {
        target_postfix[++k]=stack_peek(stack_ptr);
        stack_pop(stack_ptr);
    }
    target_postfix[++k]='\0';
    stack_destroy(stack_ptr);
}
