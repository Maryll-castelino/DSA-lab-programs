#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 		         //Data part
    struct node *next;       //Address part
}*header;
 
void createList(int n);	//Function to create list  
void traverseList(struct node *header); //Function to traverse list
void insertNodeAtBeginning(int data); //function to insert node at beginning
void insertNodeAtEnd(int data1); //function to insert node at end
void insertNodeInMiddle(int, int); //function to insert node in the middle
void deleteLastNode(); //function to delete the last  node
void deleteFirstNode(); //function to delete the first node
void deleteMiddleNode(int); //function to delete node at the middle
  
int main()
{
    int n,data, position, h,c, d = 0; 
    do
    {
    printf("\nEnter your choise:\n");
    printf("\n1. Create List");
    printf("\n2. Insert In List");
    printf("\n3. Delete From List");
    printf("\n4. Display/Traverse List");
    printf("\n5. Exit\n");
    scanf("%d", &c);
    
    
    switch(c)
    {
    	case 1:		printf("Enter the total number of nodes: ");
   					scanf("%d", &n); 
 				    createList(n); 
 				    break;
				    
		case 2:     printf("\nEnter Your Choices From Below\n");
				    printf("\n1. Insert Node At Beginning \n");
				    printf("\n2. Insert Node At End\n");
    				printf("\n3. Insert Node At Middle\n");
    				scanf("%d", &h);
						switch(h)
						{
							case 1:		printf("\n ENTER THE  Data in the list \n");
    									scanf("%d", &data);
    									insertNodeAtBeginning(data);
    									break;
    									
							case 2: 	printf("\n ENTER THE  Data in the list \n");
    									scanf("%d", &data);
        								insertNodeAtEnd(data);
        								break;
										
							case 3: 	printf("\n ENTER THE  Position in the list \n");
    									scanf("%d", &position);
                                        printf("\n ENTER THE  Data in the list \n");
    									scanf("%d", &data);
    									insertNodeInMiddle(data, position);		
										break;
										  
							default:    printf("\n\nInvalid Input!!\n");					
						}
					break;
		
		case 3:		printf("\nEnter Your Choices From Below\n");
				    printf("\n1. Delete Node At End \n");
				    printf("\n2. Delete Node At First\n");
    				printf("\n3. Delete Node At Middle\n");
    				scanf("%d", &h);
						switch(h)
						{
							case 1:		deleteLastNode();
    									break;
    									
							case 2: 	deleteFirstNode();
        								break;
										
							case 3: 	printf("Enter the position: ");
   										scanf("%d", &position); 
    									deleteMiddleNode(position);		
										break;
										  
							default:    printf("\n\n******Invalid Input******\n");					
						}
					break;
   
    	case 4:		printf("\n Data in the list after all alteration  \n");
    				traverseList(header);
        			break;
        			
        case 5:		d = d + 1;
					break;
				
	default:    printf("\n\n******Invalid Input******\n");
				
}
}
while(d == 0);

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    // A node is created by allocating memory to a structure
    newNode = (struct node *)malloc(sizeof(struct node));

    // If unable to allocate memory for head node
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
 
        newNode->data = data; //Links the data field with data
        newNode->next = NULL; //Links the address field to NULL
        header = newNode;     //Header points to the first node
        temp = newNode;       //First node is the current node
        for(i=2; i<= n; i++)
        {
            // A newNode is created by allocating memory
            newNode = (struct node *)malloc(sizeof(struct node));
        
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
        
                newNode->data = data; //Links the data field of newNode with data
                newNode->next = NULL; //Links the address field of newNode with NULL
        
                temp->next = newNode; //Links previous node i.e. temp to the newNode
                temp = newNode; 
            }
        }
    }
} 
  
void insertNodeAtBeginning(int data)
{
    struct node *newNode; 
    newNode = (struct node*)malloc(sizeof(struct node));
 
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 	//Links the data part
        newNode->next = header; 	//Links the address part
        header = newNode; 	//Makes newNode as first node
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void insertNodeAtEnd(int data1)
{
    struct node *newNode,*temp1; 
    newNode = (struct node*)malloc(sizeof(struct node));
 
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data1; 	//Links the data part
        newNode->next = NULL; 	//Links the address part
        temp1 = header; 
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=newNode;	//Makes newNode as first node
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void insertNodeInMiddle(int data1,int position)
{
	int i;
	struct node *newNode, *temp2;
	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data1; 	//Links the data part
        newNode->next = NULL;
    
       temp2=header;
       for(i=2;i<=position-1;i++)
       {
       	temp2=temp2->next;
       	if(temp2==NULL)
       	break;
	   }
	   if(temp2!=NULL)
	   {
	   	newNode->next=temp2->next;
	   	temp2->next=newNode;
	   	printf("data inserted sucessfully");
	   }
	   else
	   {
	   printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
	   }
     } 
 }

void deleteLastNode()
{
	struct node *toDelete, *secondLastNode;
	toDelete=header;
	secondLastNode=header;
	while(toDelete->next!=NULL)
	{
	secondLastNode= toDelete;
	toDelete = toDelete->next;
	}
	if(toDelete==header) {header=NULL;
	}
	else 
	{
		//Disconnects the link of second last node with last node 
		secondLastNode->next=NULL;
	}
	//delete last node
	free(toDelete);
}

  
  void deleteFirstNode()
{
    struct node *toDelete;
 
    if(header == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = header;
        header = header->next;
 
        printf("\nData deleted = %d\n", toDelete->data);
 
        // Clears the memory occupied by first node
        free(toDelete);
 
        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void deleteMiddleNode(int position)
{
	int i;
	struct node *toDelete, *prevNode;
	if(header==NULL)
	{
	printf("List is already empty");
	}
		else
		{
			toDelete = header;
			prevNode = header;
			
			for(i=2;i<=position;i++)
			{
			prevNode=toDelete;
			toDelete=toDelete->next;
			
			if(toDelete==NULL)
			break;
		   }
			if(toDelete!=NULL)
			{
			if(toDelete==header)
			header=header->next;
			prevNode->next=toDelete->next;
			toDelete->next=NULL;
			free(toDelete);
			printf("Successfully  Deleted From Middle of List");
			}
			else
			{
			printf("Invalid Position Unable to delete");
			}
			}
		}


void traverseList(struct node *header)
{
  struct node *temp;
 
  // If the list is empty i.e. head = NULL 
  if(header == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    temp = header;
    while(temp != NULL)
    {
     printf("Data = %d\n", temp->data); //Prints the data of current node
     temp = temp->next; 	//Advances the position of current node
    }
  }
} 
