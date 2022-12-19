#include<iostream>
using namespace std;
int binary(int a[],int size,int key){
int low=0;
int high = size-1;
int mid;
while (low<=high)
{
    mid=(low+high)/2;
    if (a[mid]==key)
    {
      return mid;  
    }
    else if (a[mid]>key)
    {
        high=mid-1;
    }
    else if (a[mid]<key)
    {
        low=mid+1;
    }
    
    
    
}

return 0;
}
int main(){
int a[10]={1,2,3,4,5,5,7,8,9,10};
int z;
cin>>z;
int y =binary(a,10,z);
cout<<y;

return 0;
}