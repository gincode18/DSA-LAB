#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
void swap(int a, int b, node **x)
{
    node *first = *x;
    node *second = *x;
    node *temp;
    if (a != 0 && b != 0)
    {
        for (int i = 0; i < a - 1; i++)
        {
            first = first->next;
        }
        for (int i = 0; i < b - 1; i++)
        {
            second = second->next;
        }
        temp = first->next;
        first->next = second->next;
        second->next = temp;
        temp = first->next->next;
        first->next->next = second->next->next;
        second->next->next = temp;
    }
    else
    {
        if (a == 0)
        {
            for (int i = 0; i < b - 1; i++)
            {
                second = second->next;
            }
            first = *x;
            *x = second->next;
            temp = second->next->next;
            second->next->next = first->next;
            second->next = first;
            first->next = temp;
        }
        else
        {

            for (int i = 0; i < a - 1; i++)
            {
                second = second->next;
            }
            first = *x;
            *x = second->next;
            temp = second->next->next;
            second->next->next = first->next;
            second->next = first;
            first->next = temp;
        }
    }
}
void popfirst(node **x)
{
    node *temp = *x;
    *x = (*x)->next;
    free(temp);
}
void top(node **x)
{
    int y=(*x)->data;
    }
void poplast(node *x)
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
node *merge(node *x, node *y)
{
    node *z;
    node *temp = x;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = y;
    return x;
}
void del(node** head_ref, int position)
{
  
   
    if (*head_ref == NULL)
        return;
  
    
    node* temp = *head_ref;
  
    
    if (position == 0) {
  
        
        *head_ref = temp->next;
  
        
        free(temp);
        return;
    }
  
    
    for (int i = 0; temp != NULL && i < position - 2; i++)
        temp = temp->next;
  
    
    if (temp == NULL || temp->next == NULL)
        return;
  
    
  
    node* next = temp->next->next;
  
    
    free(temp->next); 
  
  
    temp->next = next;
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
void append(node **x, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;
    node *last = *x;

    if (*x == NULL)
    {
        *x = newnode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newnode;
    return;
}

int main()
{
    node *q;
    int x, y, z;
    while (true)
    {
        cout << "1 .push element\n2. append an element \n3. printlist \n4. popfirst \n5. poplast \n6. merge a new list \n7. delete at sertain index \n8.swap two elemets\n 9. top\n";
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
            cin>>y;
            append(&q, y);
            
        }
        break;

        case (3):
        {

            checklist(q);
        }
        break;

        case (4):
        {
            popfirst(&q);
        }
        break;

        case (5):
        {
            poplast(q);
           
        }
        break;
        case (6):
        {
            node *a;
            while (true)
            {
                cout << "enter new list to merge\n 1. to push\n else to stop";

                int b, c;
                cin >> b;
                if (b == 1)
                {
                    cin >> c;
                    push(&a, c);
                    checklist(a);
                }
                else
                {
                    break;
                }
            }
            q = merge(q, a);
            
        }
        break;
        case (7):
        {
            cin >> y;
            del(&q, y);
            
        }
        break;
        case (8):
        {
            cin >> y;
            cin >> z;
            swap(y, z,&q);
            
        }
        break;
          case (9):
        {
           top(&q);
         
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