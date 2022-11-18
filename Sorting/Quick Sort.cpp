#include <iostream>

using namespace std;

int Partition(int arr[],int s,int e){
    int pivot= arr[e];
    int pIndex = s;
    for(int i=s;i<e;i++){
        if(arr[i]<=arr[e]){
            std::swap(arr[i],arr[pIndex]);
            // int temp = arr[pIndex];
            // arr[pIndex] = arr[i];
            // arr[i] = temp;
            pIndex++ ;
        }
    }
        std::swap(arr[e],arr[pIndex]);
        // int temp = arr[pIndex];
        // arr[pIndex] = arr[e];
        // arr[e] = temp;
        return pIndex;
}

void QuickSort(int arr[],int s,int e,int n){
    if(s<e){
        int p=Partition(arr,s,e);
        QuickSort(arr,s,(p-1),n);
        QuickSort(arr,(p+1),e,n);
    }
}

int main()
{

    int n;
    cout << "Enter the size of your array :- ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements for your array at index :- " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "UNSORTED ARRAY :- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
    
    QuickSort(arr,0,n-1, n);
    cout << "\nSORTED ARRAY :- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    return 0;
}