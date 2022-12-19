#include <iostream>
#define SIZE 10
#define PRIME 7

using namespace std;
 
template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}
 
int Hash(int key){
    return key % SIZE;
}
 
int PrimeHash(int key){
    return PRIME - (key % PRIME);
}
 
int DoubleHash(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0){
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}
 
void Insert(int H[], int key){
    int idx = Hash(key);
 
    if (H[idx] != 0){
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}
 
int Search(int H[], int key){
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key){
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0){
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
}
 
 
int main() {
 
    int A[5] ;
    cout<<"enter 5 numbers"<<endl;

    for (int i = 0; i < 5; i++)
    {
        cin>>A[i];
    }
    

    int n = sizeof(A)/sizeof(A[0]);
    Print(A, n, " A");
 
    // Hash Table
    int HT[10] = {0};
    for (int i=0; i<n; i++){
        Insert(HT, A[i]);
    }
    Print(HT, SIZE, "HT");
 int x;
 cout<<"enter key to find "<<endl;
 cin>>x;

    int index = Search(HT, x);
    cout << "key found at: " << index << endl;
 
   
 
    return 0;
}