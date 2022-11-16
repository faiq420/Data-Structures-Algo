#include <iostream>

using namespace std;

void Merge(int arr[],int l,int m,int r,int n){
    int i=l;	//index of left subarray
    int j=m+1;	//index of right subarray
    int k=l;	//index of temporary array
    int temp[n];
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {     //comparing between left subarray and right subarray
            temp[k] = arr[i];         //element of left subarray copying onto temp array
            i++; k++;
        } 
        else {
            temp[k] = arr[j];
            j++; k++;
        }
    }

    while (i <= m) {
        temp[k] = arr[i];           //when right subarray elements are finished,elements of left subarray are copied 
        i++; k++;
    }

    while (j <= r) {
        temp[k] = arr[j];           //when left subarray elements are finished,elements of right subarray are copied 
        j++; k++;
    }

    for (int x = l; x <= r; x++) {
        arr[x] = temp[x];           //temp array elements copying in main array
    }
}

void MergeSort(int arr[], int l, int r,int n){
    if(l<r){
        int m=(l+r)/2;
        MergeSort(arr,l,m,n);
        MergeSort(arr,m+1,r,n);
        Merge(arr,l,m,r,n);
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
    MergeSort(arr,0,n-1, n);
    cout << "\nSORTED ARRAY :- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    return 0;
}
