#include <stdio.h>
#include <stdlib.h>

/* Structure with a node and a pointer */
struct node
{
    int data;
    struct node *next;
}*rear,*front,*temp,*newNode;

/* Initialising front and rear in empty list */
void create()
{
    front = rear = NULL;
}

void enqueue(int data1)
{
    //struct node *newNode,*temp1; 
    newNode = (struct node*)malloc(sizeof(struct node));
 
    if(newNode == NULL)
    {
        
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data1; 	//Links the data part
        newNode->next = NULL; 	//Links the address part
         
        if(rear != NULL)
        {
            rear -> next = newNode;
            rear = newNode;  // Make the new node as REAR
            
            printf("\n# '%d' INSERTED SUCCESSFULLY\n\n", data1);
        }
        else 
        {
            front = rear = newNode;  // In a empty queue, the inserted element becomes FRONT and REAR
            
            printf("\n# '%d' INSERTED SUCCESSFULLY\n\n", data1);
        }
    }
}



void dequeue()
{
    struct node *toDelete;
 
    if(front == NULL)
    {
        
        printf("\n# Queue is already empty.\n\n");
    }
    else
    {
        toDelete = front;
        front = front->next;

        
        printf("\n# Data deleted = %d\n", toDelete->data);
 
        /* Clears the memory occupied by first node*/
        free(toDelete);
 
        printf("# SUCCESSFULLY DELETED FIRST NODE FROM LIST\n\n");
    }
}


/* Function to check if thw queue is empty */
int empty()
{
    if(front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Function to display elements */
void display()
{
    if(empty()) 
    {
        
        printf("\n# EMPTY QUEUE\n\n");
    }
    else
    {
        temp = front;
        
        printf("\n# QUEUE ELEMENTS : ");
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("\n\n");
    }
}

/* Main Function */
int main()
{
    
    int choice, data;
    while(1)
    {
        printf("Enter your choice:\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n\n->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("enter the data to be enqueued: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\n# Invalid selection!\n");
            break;
        }
    }
    return 0;
}