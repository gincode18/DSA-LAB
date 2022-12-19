#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

void top(node **x)
{
    int y=(*x)->data;
    cout<<y<<endl;
    }
void pop(node *x)
{
    node *temp = x;
    node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = (temp)->next;
    }
    prev->next = NULL;

    free(temp);
}


void push(node **x, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = *x;

    *x = newnode;
}
void checklist(node *x)
{
    while (x != NULL)
    {
        cout << x->data << "--->";
        x = x->next;
    }
    cout<<endl;
}


int main()
{
    node *q;
    int x, y, z;
    while (true)
    {
        cout << "1 .push element\n2. top elment \n3. pop \n4. print list \n";
        checklist(q);
        cin >> x;
        switch (x)
        {
        case (1):
        {
            cin >> y;
            push(&q, y);
         
        }
        break;

        case (2):
        {
          
            top(&q);
            
        }
        break;

        case (3):
        {

            pop(q);
           
        }
        break;

        case (4):
        {
             checklist(q);
        }
        break;

       
        default:
        {
            break;
        }
       
        }
    }
    return 0;
}