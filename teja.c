#include<stdio.h>
#include<stdlib.h>
struct node
{
int value;
struct node *left_child, *right_child;
};

struct node *new_node(int value)
{
struct node *tmp = (struct node *)malloc(sizeof(struct node));
tmp->value = value;
tmp->left_child = tmp->right_child = NULL;
return tmp;
}

void inorder(struct node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{
inorder(root_node->left_child);
printf("%d \n", root_node->value);
inorder(root_node->right_child);
}
}
void postorder(struct node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{

postorder(root_node->left_child);

postorder(root_node->right_child);
printf("%d \n", root_node->value);
}
}

struct node* insert_node(struct node* node, int value) // inserting nodes!
{

if (node == NULL) return new_node(value);
if (value < node->value)
{
node->left_child = insert_node(node->left_child, value);
}
else if (value > node->value)
{
node->right_child = insert_node(node->right_child, value);
}
return node;
}
int maxDepth(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left_child);
        int rDepth = maxDepth(node->right_child);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}


int main()
{



struct node *root_node = NULL;
root_node = insert_node(root_node, 25);

insert_node(root_node, 20);
insert_node(root_node, 36);
insert_node(root_node, 10);
insert_node(root_node, 22);
insert_node(root_node, 30);
insert_node(root_node, 40);
insert_node(root_node, 5);
insert_node(root_node, 12);
insert_node(root_node, 28);
insert_node(root_node, 38);
insert_node(root_node, 48);
insert_node(root_node, 1);
insert_node(root_node, 8);
insert_node(root_node, 15);
insert_node(root_node, 45);
insert_node(root_node, 50);
root_node->left_child->left_child->right_child->left_child=new_node(19);
root_node->right_child->right_child->left_child->left_child=new_node(49);

inorder(root_node);
printf("height %d \n",maxDepth(root_node));
postorder(root_node);


return 0;
}