#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int data; 
	struct node *left, *right;
}; 

void inorder(struct node *root) 
{   
    if (root != NULL)
	{ 
		inorder(root->left); 
		printf("%d ", root->data); 
		inorder(root->right); 
	}
} 

struct node* insert(struct node* root, int key) 
{ 
	struct node * newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
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

struct node* search(struct node* root, int key)
{
    if (root == NULL || root -> data == key)
     return root;
    else if (key < root -> data)
     return root ->left = search(root->left,key);
    else 
     return root -> right = search(root -> right, key);
    
}

struct node* minValueNode(struct node* root) 
{ 
    struct node* current = root; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

int main()
{ 
	struct node *root = NULL;
    struct node *S = NULL; 
    int ch, data;
    while (1) 
    {
        printf("Choose an option:\n0. EXIT\n1. Insert node\n2. Delete node\n3. Traverse the tree\n4. Search the tree\n-> ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 0:
                exit(0);
            case 1:
                printf("\nEnter the node to be inserted : ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter the node to be deleted: ");
                scanf("%d", &data);
                deleteNode(root, data);
                break;
            case 3:
                printf("Inorder traversal of the tree : ");
                inorder(root);
                printf("\n\n");
                break;
            case 4:
                printf("Enter the node to be searched: ");
                scanf("%d", &data);
                S = search(root, data);
                if(root == NULL)
                {
                    printf("\nNot Found");
                }
                else
                {
                printf("\nFound -> %d\n\n", S->data);
                }
                break;
            default :
                printf("Invalid option selected!\n\n");
        }
    }
	return 0; 
} 