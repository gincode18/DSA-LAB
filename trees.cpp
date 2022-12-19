#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	
};
class stack
{
public:
	int top;
	node** st;
	
	stack() { top = -1;
	st=new node*(); }
	node* toop()
	{
		return *(st+top);
	}
	void pop()
	{
		top = top - 1;
	}
	void push(node *temp)
	{
		top = top + 1;
       st[top] = temp;
	}
	int isempty(){
		if(top==-1){
			return 1;}
		else{
		return 0;	
		}
		
	}

};


node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void iterativePreorder(node* a){
	
	node *z=new node();
	stack s;
	s.push(a);
	while (!s.isempty())
	{
	z=s.toop();	
	cout<<z->data<<" ";
	s.pop();
	if (z->right!=NULL)
	{
		s.push(z->right);
	}
	if (z->left!=NULL)
	{
		s.push(z->left);
	}
	

	}
}
int main()
{struct node* root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(2);
    iterativePreorder(root);
	

	return 0;
}