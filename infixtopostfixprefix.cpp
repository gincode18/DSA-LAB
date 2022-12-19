#include <iostream>
#include <cstring>

using namespace std;

char Operators[1000], postfix[1000], prefix[1000];
int OperatorTop = -1, postfixTop = -1, prefixTop = -1;

int precedence(char Operator)
{
    switch (Operator)
    {
   case '^':
        return 2;
        break;
    case '*':
    case '/':
        return 1;
        break;
    case '+':
    case '-':
        return 0;
        break;
    default:
        return -1;
    }
}

bool isOperator(char ch)
{
    if (precedence(ch) != -1)
    {
        return true;
    }
    return false;
}

void pushOperator(char ch)
{
    if (OperatorTop == 99)
    {
        cout << "oOVerflow\n";
    }
    Operators[++OperatorTop] = ch;
}

char pop_Operator()
{
    if (OperatorTop == -1)
    {
        cout << "oUnderflow\n";
        return '0';
    }
    else
    {
        return Operators[OperatorTop--];
    }
}

void pushPostfix(char ch)
{
    if (postfixTop == 99)
    {
        cout << "pOverflow\n";
    }
    else
    {
        postfix[++postfixTop] = ch;
    }
}

void emptyOperatorStack()
{
    while (OperatorTop != -1)
    {
        pushPostfix(pop_Operator());
    }
}

void toPostfix(char *expression)
{

    for (int i = 0; expression[i] != '\0'; i++)
    {

        // is Operator
        if (isOperator(expression[i]))
        {

            // Operator stack empty
            if (OperatorTop == -1)
            {
                Operators[++OperatorTop] = expression[i];
            }
            // if not empty
            else
            {

                // if higher precedence
                if (precedence(expression[i]) <= precedence(Operators[OperatorTop]))
                {
                    while (precedence(expression[i]) <= precedence(Operators[OperatorTop]))
                    {
                        pushPostfix(pop_Operator());
                    }
                    pushOperator(expression[i]);
                }
                // if lower precedence
                else
                {
                    pushOperator(expression[i]);
                }
            }
        }
        // check if it's closing bracket
        else if (expression[i] == ')')
        {
            while (Operators[OperatorTop] != '(')
            {
                pushPostfix(pop_Operator());
            }
            pop_Operator();
        }
        else if (expression[i] == '(')
        {
            pushOperator(expression[i]);
        }

        // is operand
        else
        {
            pushPostfix(expression[i]);
        }
    }
    emptyOperatorStack();
}

void toPrefix(char *expression)
{
    int len = strlen(expression);
    char rev_expression[100];
    int i = len - 1, j = 0;

    for (; i >= 0; i--)
    {
        rev_expression[j++] = expression[i];
    }
    rev_expression[j] = '\0';
    toPostfix(rev_expression);

    for (i = len - 1, j = 0; i >= 0; i--)
    {
        prefix[j++] = postfix[i];
    }
}

int main()
{
    char expression[100];
    int choice;
    cout << "Enter expression\n";
    cin >> expression;

    toPostfix(expression);
    cout << postfix;
    cout << endl;
    return 0;
}
