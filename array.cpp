#include<stdio.h>
#include<stack>
int main(){
int x;
float sum=0;
printf("Input the number of elements to store in the array:");
scanf("%d",&x);
printf("enter %d elements\n",x);

int a[x];
for(int i=0;i<x;i++)  {
printf("element - %d:",i);
scanf("%d",&a[i]);
}
for (int j = 0; j < x; ++j) {
sum =sum+a[j];
  }
int y;
printf("Avg of all elements stored in the array is :%f",sum/x);
printf("enter no you want to find\n");
scanf("%d",&y);
for (int i = 0; i < x; i++)
{
    if (a[i]==y)
    {
        printf("position of element is %d\n",i);
    }
    
}

return 0;




}
