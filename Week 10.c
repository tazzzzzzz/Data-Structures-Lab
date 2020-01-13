#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node
{
 struct Node *right,*left;
 char data;
} Node;


//Create Binary Expression tree from a string in postfix form  of length len
Node * createExpressionTree(char* a,int len);


//print the preorder traversal of the Binary Expression Tree
void preorder(Node *);


//print the postorder traversal of the Binary Expression Tree
void postorder(Node *);


//print the inorder traversal of the Binary Expression Tree
void inorder(Node *);


//Frees the space used by the Binary Expression Tree
void freeTree(Node * root);

Node *pop(Node **,int *);
int isoper(char);
int main()
{
  char postfix[100];
  int len;
  Node *root;
  int loop = 1,code;
  while(loop)
  {
    scanf("%d",&code);
    switch(code)
    {
        case 1:
            scanf("%s",postfix);
            len=strlen(postfix);
            root = createExpressionTree(postfix,len);
            break;

        case 2:
            inorder(root);
            printf("\n");
            break;

        case 3:
            preorder(root);
            printf("\n");
            break;

        case 4:
            postorder(root);
            printf("\n");
            break;

        default:
            loop = 0;
            break;

    }

  }
 freeTree(root);
    return 0;
}


Node * createExpressionTree(char* exp,int len)
{
 Node *temp;
 Node **stack[100];
 int top = -1,i = 0;
 while(exp[i] != '\0')
 {
    char ch = exp[i];
    temp = (Node*)malloc(sizeof(Node));
    temp->data = ch;
    temp->left = temp->right = NULL;
    if(isoper(ch))
    {
     temp->right = pop(stack,&top);
     temp->left = pop(stack,&top);
     push(stack,&top,temp);
    }
    else
        push(stack,&top,temp);
    i++;
 } return(pop(stack,&top));
}
void push(Node **stack,int *t,Node* temp)
{
    ++*t;
    stack[*t] = temp;
}
Node *pop(Node** stack, int *t)
{
    Node* temp;
    temp = stack[*t];
    --*t;
    return temp;
}
int isoper(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        return 1;
        default:
        return 0;
    }
}
void inorder(Node *root)
{
 if (root!= NULL)
 {
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right);
 }
}

void preorder(Node *root)
{
 if (root!= NULL)
 {
    printf("%c",root->data);
    preorder(root->left);
    preorder(root->right);
 }

}

void postorder(Node *root)
{
 if (root!= NULL)
 {
    postorder(root->left);
    postorder(root->right);
    printf("%c",root->data);
 }
}


void freeTree(Node * root)
{

}
