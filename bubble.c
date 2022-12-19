#include<iostream>

using namespace std;

int ls(int arr[], int target, int size){
    for(int i = 0;i<size;i++){
        if(target == arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int target;
    cout << "Enter target: ";
    cin >> target;
    cout << "element found at :" << ls(arr,target,size);
    return 0;
}