#include<stdio.h>
#include<stdlib.h>

struct Queue { 
    int front, rear, size; 
    int capacity; 
    int* array; 
};

void enqueue(struct Queue*);
void dequeue(struct Queue*);
void peek(struct Queue*);
struct Queue* createQueue(int);
int isfull(struct Queue*);
int isEmpty(struct Queue*);

void main()
{
	int n,ch;
	printf("Enter The limit of the Queue:-");
	scanf("%d",&n);
	struct Queue* que = createQueue(n);
	while (1) {
		printf("\nEnter your choice:-\n");
		printf("0.EXIT\n1.Enqueue\n2.Dequeue\n3.Peek\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				enqueue(que);
				break;
			case 2:
				dequeue(que);
				break;
			case 3:
				peek(que);
				break;
			default:
				printf("Enter again!");
		}
	}
}

void enqueue(struct Queue* que) 
{ 
	int data;
	if(isfull(que))
	{
		
		printf("\n# Queue is full\n");
	}
	else
	{
		que->rear=(que->rear+1);
		printf("Enter the data to add :-");
		scanf("%d",&data);
		que->array[que->rear]=data; 
		que->size=que->size+1;
		
		printf("\n# '%d' enqueued to queue at pos '%d'\n",data, que->rear);
	}
}

void dequeue(struct Queue* que)
{
	if(isEmpty(que))
	{
		
		printf("\n# Queue Underflow\n");
	}
	else
	{		
		
		printf("\n# '%d' is dequeued from the queue\n", que->array[que->front]);
		que->front = que->front + 1;
		que->size=que->size-1;
	}
}

void peek(struct Queue* que)
{
	int first,last;
	if (isEmpty(que))
	{
		
		printf("\n# Queue Underflow\n");
	} 
	else
	{
		first=que->array[que->front];
		last=que->array[que->rear];
		
		printf("\n# Front item is '%d'\n", first); 
		printf("# Rear item is '%d'\n\n", last);
	}
  
}

struct Queue* createQueue(int capacity) 
{ 
    struct Queue* que = (struct Queue*)malloc(sizeof(struct Queue)); 
    que->capacity = capacity; 
    que->front = que->size = 0; 
    que->rear = - 1; 
    que->array = (int*)malloc(que->capacity * sizeof(int)); 
    return que; 
} 

int isfull(struct Queue* que) 
{ 
    return (que->rear == que->capacity-1); 
} 

int isEmpty(struct Queue* que) 
{ 
    return (que->size == 0); 
} 