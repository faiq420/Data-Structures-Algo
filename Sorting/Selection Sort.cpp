#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    SelectionSort(arr, n);
    cout << "\nSORTED ARRAY :- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    return 0;
}