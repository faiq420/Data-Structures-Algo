#include <iostream>
#include <algorithm>

using namespace std;

int BinarySearch(int arr[],int left,int right,int x){
    while(left<=right){
        int mid= left + (right - left)/2;
        if(x==arr[mid]){
            return mid;
        }
        else if(arr[mid] > x){
            right = mid-1;
        }
        else{
            left=mid+1;
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
    std::sort(array,array+n);       //sort(<initial index>,<last index>);
    int result = BinarySearch(array,0,n-1,x);
    if(result==-1){
        cout<<"Element not found."<<endl;
    }
    else{
        cout<<"Element "<<x<<" found at position "<<result+1<<" ."<<endl;
    }
}