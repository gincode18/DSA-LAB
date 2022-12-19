#include<stdio.h>  
#include<stdlib.h>

struct node  
{  
    int key;  
    struct node *left;  
    struct node *right;  
};  
  
 
struct node *getNode(int val)  
{  
    struct node *newNode;  
  
    newNode = malloc(sizeof(struct node));  
  
    newNode->key   = val;  
    newNode->left  = NULL;  
    newNode->right = NULL;  
  
    return newNode;  
}  
  
 
struct node *insertNode(struct node *root, int val)  
{  
     if(root == NULL)  
         return getNode(val);  
  
     if(root->key < val)  
         root->right = insertNode(root->right,val);  
  
     if(root->key > val)  
         root->left = insertNode(root->left,val);  
  
     return root;  
}  
  
 
void preorder(struct node *root)  
{  
    if(root == NULL)  
        return;  
  
     
    printf("%d ",root->key);  
  
    
    preorder(root->left);  
  
   
    preorder(root->right);  
}  
void postorder(struct node *root)  
{  
    if(root == NULL)  
        return;  
  
    
    postorder(root->left);  
  
  
    postorder(root->right);  
  
     
    printf("%d ",root->key);  
}  
void inorder(struct node *root)  
{  
    if(root == NULL)  
        return;  
  
    inorder(root->left);  
  
   
    printf("%d ",root->key);  
  
    inorder(root->right);  
}  
int main()  
{  
   struct node *root = NULL;  
  
   int data;  
    char ch;  
        while (1>0)
     
         
        {  
           
            printf("\n1. insert");  
            printf("\n2. ineorder Traversal\n"); 
            printf("\n3. preorder Traversal).\n"); 
            printf("\n4. postorder Traversal).\n"); 
  
            int choice;  
            scanf("%d",&choice);              
            switch (choice)  
            {  
            case 1 :   
                printf("\nEnter the value\n");  
                scanf("%d",&data);  
                root = insertNode(root,data);                    
                break;  
            case 2 :   
                printf("\nInreorder Traversal::\n");  
                inorder(root);  
                break; 
            case 3 :   
                printf("\nPreorder Traversal \n");  
                preorder(root);  
                break;                           
            case 4 :   
                printf("\nPostorder Traversal \n");  
                postorder(root);  
                break;   
            default :   
                printf("Wrong Entry\n");  
                break;     
            }  
  
                                   
        }  
    
   return 0;  
}  