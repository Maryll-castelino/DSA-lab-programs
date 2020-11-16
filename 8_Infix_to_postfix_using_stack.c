#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

#define SIZE 100

struct Stack { 
    int top; 
    int capacity;  
    char* array; 
}; 
  
struct Stack* create_Stack(int capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (char*)malloc(sizeof(stack->capacity)); 
    return stack; 
}

int isFull(struct Stack* stack) 
{ 
    if (stack->top == stack->capacity - 1)
        {
            printf("------STACK FULL----\n");
            return 1;
        }
    else
       return 0;
} 

void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return;
    stack->top++;
    stack->array[stack->top] = item; 
} 

int isEmpty(struct Stack* stack) 
{ 
    if(stack->top == -1)
    {
        printf("-----STACK EMPTY------\n");
        return 1;
    }
    else
        return 0;
} 

char pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return 0;
    char poped_element = stack->array[stack->top];
    stack->top--;
    return(poped_element);
} 

int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return stack->top; 
    return stack->array[stack->top]; 
} 

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{ 
	int i, j;
	char item;
	char x;
 	struct Stack* stack = create_Stack(SIZE); 
	push(stack,'(');                        
	strcat(infix_exp,")");      

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')    
	{
		if(item == '(')
		{
			push(stack,item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;
			j++;
		}
		else if(is_operator(item) == 1)        
		{
			x=pop(stack);
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  
				j++;
				x = pop(stack);                       
			}
			push(stack,x);
			push(stack,item);          
		}
		else if(item == ')')         
		{
			x = pop(stack);                   
			while(x != '(')                
			{
				postfix_exp[j] = x;
				j++;
				x = pop(stack);
			}
		}
		else
		{ 
			printf("\nInvalid infix Expression.\n");        
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; 
	} 
	if(stack->top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0';
}

int main()
{
	char infix[SIZE], postfix[SIZE];   
	printf("\nEnter Infix expression : ");
	scanf("%s", infix);
	InfixToPostfix(infix,postfix);                  
	printf("Postfix Expression: ");
	puts(postfix);                   
	return 0;
}
