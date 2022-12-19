#include <iostream>
using namespace std;
class stack
{
public:
    int t;
    char st[100];
    stack() { t = -1; }
    char top()
    {

        return st[t];
    }
    char pop()
    {
        char temp = top();
        t = t - 1;
        return temp;
    }
    void push(char temp)
    {

        t = t + 1;

        st[t] = temp;
    }
    void result()
    {for (int i = 0; i <= t; i++)
    {
        cout<<st[i];
    }
    
    }};
int pre(char x){
if (x=='+'||x=='-')
{
    return 1;
}
else if (x=='*'||x=='/')
{
    return 2;
}
else{
    return 0;
}

}
int isoperator(char x){
    if (x=='+'||x=='-'||x=='*'||x=='/')
    {
        return 1;
    }
    else{
        return 0;
    }
}
stack infixtoprefix(string x){
stack postfix;
stack oper;

int i=0;
while (x[i]!='\0')
{ 

    if (isoperator(x[i]))
{
    
    if (pre(x[i])>pre(oper.top()))
{cout<<">operator pushing"<<x[i]<<endl;
   oper.push(x[i]); 
}
else if (pre(x[i])<=pre(oper.top()))
{
    while (oper.t>=0)
    {cout<<"<operaotr removing"<<oper.top()<<endl;
        postfix.push(oper.pop());
    }
    cout<<">operator pushing"<<x[i]<<endl;
    oper.push(x[i]);
}
}
else{
cout<<"operand pushing"<<x[i]<<endl;
postfix.push(x[i]);
}


i++;
    
}
while (oper.t>=0)
{cout<<"operator left in stack pushing"<<oper.top()<<endl;
    postfix.push(oper.pop());
}
return postfix;
}
int main()
{

    string x = "a+b*c-f+g*h-i";
stack y= infixtoprefix(x);

y.result();


    return 0;
}