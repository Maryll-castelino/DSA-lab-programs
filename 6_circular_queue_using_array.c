#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
        printf("\n# The element enqueued is %d", x);
    } else if ((rear + 1) % 5 == front) {
        printf("\n# Queue is full!\n");
    } else {
        rear = (rear + 1) % 5;
        queue[rear] = x;
        printf("\n# The element enqueued is %d", x);
    }
}

void dequeue() {
    if (front == -1 && rear == -1){
        printf("\n# Queue is empty!\n");
    } else if (front == rear) {
        printf("\n# The dequeued element is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("\n# The dequeued element is %d\n", queue[front]);
        front = (front + 1) % 5;
    }
}

void display() {
    int i = front;
    if (front == -1 && rear == -1){
        printf("\n# Queue is empty!\n");
    } else {
        printf("\n# The queue is :");
        while(i != rear){
            printf("\t%d", queue[i]);
            i = (i + 1) % 5;
        }
        printf("\t%d\n", queue[rear]);
    }
}

void main(){
    
    int choice, data;
    while(1)
    {
        printf("\nEnter your choice:\n0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n\n->");
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
}