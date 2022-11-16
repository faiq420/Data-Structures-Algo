#include <iostream>

using namespace std;

void InsertionSort(int arr[], int n)
{
    int key = 0;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    InsertionSort(arr, n);
    cout << "\nSORTED ARRAY :- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    return 0;
}