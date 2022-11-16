#include <iostream>

using namespace std;

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp= arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
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
    BubbleSort(arr, n);
    cout << "\nSORTED ARRAY :- ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }

    return 0;
}