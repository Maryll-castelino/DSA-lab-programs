/*
Name : Maryll Castelino
Class : 3BTCS B
Reg no : 1960357
*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

struct tree
{	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* insert(struct tree* root,int key) 
{ 
	struct tree* newnode;
	newnode = (struct tree*)malloc(sizeof(struct tree));
	newnode -> data = key;
	newnode -> left = newnode -> right = NULL;
	if (root == NULL) 
	 root = newnode;
	if (key < root->data) 
		root -> left = insert(root->left, key); 
	else if (key > root->data) 
		root -> right = insert(root->right, key); 
	return root; 
} 

void printInorder(struct tree* root)
{
	if(root==NULL)
    {
	    return;
    }
	printInorder(root->left);
	printf("%d->",root->data);
	printInorder(root->right);	
}

void printPreorder(struct tree* root)
{
	if(root==NULL) {
	    return;
    }
	printf("%d->",root->data);
	printPreorder(root->left);
	printPreorder(root->right);	
}

void printPostorder(struct tree* root)
{
	if(root==NULL) {
	    return;
    }
	printPostorder(root->left);
	printPostorder(root->right);
	printf("%d->",root->data);
}

void main()
{
	int data,ch;
	struct tree* root;
	root=NULL;
    while (1) 
    {
        printf("\nEnter the choice of traversal:-\n0. EXIT\n1. Enter Data Into Binary Tree\n2. Inorder Traversal\n3. Preorder traversal\n4. Postorder traversal\n->");
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:
                exit(0);
            case 1:
                printf("Enter The elements of the tree:-");
                scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2:
                printf("Inorder Traversal\n");
                printInorder(root);
                break;
            case 3:
                printf("Preorder Traversal\n");
                printPreorder(root);
                break;
            case 4:
                printf("Postorder Traversal\n");
                printPostorder(root);
                break;
            default:
                printf("Wrong Choice");
        }
    }
}