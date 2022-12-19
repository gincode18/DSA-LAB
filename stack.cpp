#include <iostream>

using namespace std;

int main()
{
    stack a;
    int x;
    cout << "enter choice \n 1. for push \n 2.for pop \n 3. print stack \n 4. to exit\n";

    while (x != 4)
    {
        cout << "enter choise \n";
        cin >> x;
        switch (x)
        {
        case (1):
        {
            a.push();
        }

        break;
        case (2):
        {
            a.pop();
        }
        break;
        case (3):
        {
            a.result();
        }
        break;
        case (4):
        {
        }
        break;
        default:
        {
            cout << "enter a valid argument\n";
        }
        break;
        }
    }
    cout << "exiting";

    return 0;
}