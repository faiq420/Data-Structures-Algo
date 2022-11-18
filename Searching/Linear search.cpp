#include <iostream>
using namespace std;

int LinearSearch(int arr[],int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,x;
    cout<<"Enter the number of elements in the array :- ";
    cin>>n;
    int *array= new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element at position "<<i+1<<" :- ";
        cin>>array[i];
    }
    cout<<"Enter the number to be searched :- ";
    cin>>x;
    int result=LinearSearch(array,n,x);
    if(result==-1){
        cout<<"Search failed. Element not found."<<endl;
    }
    else{
        cout<<"Element "<<x<<" found at position "<<result+1<<" ."<<endl;
    }
}