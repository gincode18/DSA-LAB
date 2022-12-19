#include <iostream>
using namespace std;
int swap(int *a, int *b)
{
    int temp;
    temp = *a;ci
    *a = *b;
    *b = temp;
    return 0;
}
int main()
{
    int a[10] = {1, 22, 323, 45, 54, 6, 4, 2, 21, 32};
    int n = 10;
    int key;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        int j = i - 1;
        while (j >= 0 & a[j] > key)
        {

            a[j + 1] = a[j];

            j--;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}