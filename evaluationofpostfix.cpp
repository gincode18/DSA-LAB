#include <iostream>
using namespace std;
class stack
{
public:
    int top;
    int st[100];
    stack() { top = -1; }
    void toop()
    {
        cout << st[top];
    }
    int pop()
    {

        int temp;
        temp = st[top];
        top = top - 1;

        return temp;
    }
    void push(int temp)
    {

        top = top + 1;

        st[top] = temp;
    }
    void result()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << endl;
        }
    }
};
int isoperator(char x)
{
    if (x == '+' || x == '*' || x == '-' || x == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void evaluate(string x)
{
    stack y;
    for (int i = 0; x[i] != '\0'; i++)
    {
        if (isoperator(x[i]))
        {
           int num1= y.pop();
            int num2=y.pop();
        switch (x[i])
        {
        case ('+'):
        y.push(num1+num2);
           break;
        case ('-'):
        y.push(num2-num1);
           break;
        case ('*'):
        y.push(num1*num2);
           break;
        case ('/'):
        y.push(num2/num1);
           break;
        default:
            break;
        }
        }
        else
        {
            y.push(x[i]-'0');
        }
    }
    cout<<y.pop();
}
int main()
{
    string postfix;
    cin>>postfix;
evaluate(postfix);
    return 0;
}