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
   int a[10]={21,32,3,32,4,41,234,34,324,423};
int n=10;
for (int i = 0; i < n; i++)
{
    for (int j = i+1; j < n; j++)
    {
        if (a[i]>a[j])
        {
            swap(a[i],a[j]);
        }
        
    }
    
}
for (int i = 0; i < n; i++)
{
    cout<<a[i]<<" ";
}



    return 0;
}