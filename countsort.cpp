#include <iostream>
using namespace std;
int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int main()
{
    int a[10] = {1, 22, 323, 45, 54, 6, 4, 2, 21, 32};
    int n = 10;
    int key;
    for (int i = 0; i < n-1; i++)
    {if (a[i]>a[i+1])
    {
        swap(a[i],a[i+1]);
    }
    
     
    }
    int max=a[9];
    int b[max+1];
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int x=0;
    for (int i = 0; i < max+1; i++)
    {
        if (b[i]!=0)
        {
            for (int j = 0; j <b[i]; j++)
            {
                a[x]=i;
                x++;
            }
            
        }
        
    }
    
    
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}