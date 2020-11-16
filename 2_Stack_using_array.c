#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int top; 		
	int capacity;
	int *array;     
         
};

struct node* createStack(int);
void push(struct node*);
void pop(struct node*);
void display(struct node*);
int isFull(struct node*);
int isEmpty(struct node*);

void main()
{
	int n,choice;
	
	printf("Enter The limit of the stack:-");
	scanf("%d",&n);

	struct node* st = createStack(n);
	while (1) {
		printf("\nEnter Your Choice:-");
		printf("\n0.EXIT\n1.Push\n2.Pop\n3.Peek\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				exit(0);
				break;
			case 1:
				push(st);
				break;
			case 2:
				pop(st);
				break;
			case 3:
				display(st);
				break;
			default :
				printf("Enter again!");
		}
	}
}

void push(struct node* st)
{	
	int val;
	if(isFull(st)) {
		
		printf("\n# Stack is Full\n");
	}
	else
	{
		st->top=st->top+1;
		printf("Enter the value:");
		scanf("%d",&val);
		st->array[st->top]=val;
		
		printf("\n# '%d' has been pushed\n",val);
	}
}

void pop(struct node* st)
{
	int val;
	if(isEmpty(st)) {
		
		printf("\n# Stack is empty.\n");
	}
	else {
		val=st->array[st->top];
		st->top=st->top-1;
		
		printf("\n# '%d'  has been poped\n",val);
	}
}
void display(struct node* st)
{	
	
	if(isEmpty(st)) {
		
		printf("\n# Stack is emplty.\n");
	}
	else
	{
		printf("\n# The data at top is '%d'\n",st->array[st->top]);
	}
}
struct node* createStack(int capacity)
{
	struct node* st = (struct node*)malloc(sizeof(struct node));
	st->capacity=capacity;
	st->top=-1;
	st->array=(int*)malloc(sizeof(struct node));
	return st;
	
}
int isFull(struct node* st)
{
	return st->top==st->capacity-1;
}
int isEmpty(struct node* st)
{
	return st->top==-1;
}
