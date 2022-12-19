#include<iostream>
using namespace std;
int swap(int* a, int* b){
int temp;
temp=*a;
*a=*b;
*b=temp;
return 0;
}
int main(){
int a[10]={1,22,323,45,54,6,4,2,21,32};
int n=10;
int temp;
for (int i = 0; i < n-1; i++)
{for (int j = 0; j <n-i-1 ; j++)
{
    if (a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }
    
}


    
}
for (int i = 0; i < 10; i++)
{
    cout<<a[i]<<" ";
}

return 0;
} 