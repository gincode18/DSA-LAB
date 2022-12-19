#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	
};




#include <iostream>
using namespace std;
int main() {
   string arr[5] = {"dgvy", "gyufsd", "ugfuyeg", "usdvg", "sdugfu"};
   string *ptr = &arr[0];
   cout<<"The values in the array are: ";
   for(int i = 0; i < 5; i++) {
      cout<< *ptr <<" ";
      ptr=ptr+1;
   }

   return 0;}
