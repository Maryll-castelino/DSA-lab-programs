#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct st { 
    int data;
    struct st *next; 
}*top;

struct st* create_stack()
{
	struct st*stack = (struct st*)malloc(sizeof(struct st));
	return stack;
}
	 
void push(struct st*);
void pop(struct st*);
void display(struct st*);

void main()
{	int ch;
	struct st* stack = create_stack();
	while (1) {
        printf("\nEnter Your Choice:-\n");
        printf("0.Exit\n1.Push\n2.Pop\n3.Display\n\n");
        scanf("%d",&ch);
            switch(ch)
            {
                case 0:
                    exit(0);
                case 1:
                    push(stack);
                    break;
                case 2:
                    pop(stack);
                    break;
                case 3:
                    display(stack);
                    break;
                default:
                    printf("Enter again!!!");
        }
	}
}

void push(struct st* stack)
{	
	int data;
	struct st* newNode = (struct st*)malloc(sizeof(struct st));
	printf("Enter the data to be Pushed : ");
	scanf("%d",&data);
	if(newNode == NULL) 
    {
        
        printf("\n# Unable to allocate memory.\n");
    }
    else 
    {
        newNode->data = data; 	//Links the data part
        newNode->next = top; 	//Links the address part
        top = newNode; 	//Makes newNode as first node
        
        printf("\n# '%d' pushed inside the stack\n",newNode->data);
    }
}

void pop(struct st* stack)
{	
    struct st *toDelete;
 
    if(top == NULL)
    {
        
        printf("\n# List is already empty.\n");
    }
    else
    {
        toDelete = top;
        top = top->next;
        
        printf("\n# '%d' is poped from the stack\n", toDelete->data);
        free(toDelete);
    }
}

void display(struct st* stack)
{
    struct st *temp;
    
    if(top == NULL)
    {
        
        printf("List is empty.");
    }
    else
    { 
        temp = top;
        
        printf("The stack contains :\n\n");
        while(temp != NULL)
        {
            printf("\t%d\n", temp->data); 
            temp = temp->next; 
        }
    }
} 
