#include <iostream>
#include <string>
using namespace std;

void minHeap(int *array,int arraysize){
	int j=2;
	while(j<=arraysize)			//if only 1 node, it will be directly returned.
	{
		if(array[j] < array[j/2])
		{			//if node<parent then swap otherwise goto next index and compare
			int temp= array[j/2];
			array[j / 2] = array[j];
			array[j] = temp;
		}
		else
		{
			j++;
			continue;
		}
	}
	return;
}

void maxHeap(int *array,int arraysize){
	int j=2;
	while(j<=arraysize)			//if only 1 node, it will be directly returned.
	{
		if(array[j] > array[j/2])
		{			//if node>parent then swap otherwise goto next index and compare
			int temp= array[j/2];
			array[j/2] = array[j];
			array[j] = temp;
//		swap(array[j],array[j/2]);
		}
		else
		{
			j++;
			continue;
		}
	}
	return;
}

void DeleteTree(int *array, int size)
{
    int i = 1;
    int j = 1;
    array[1] = 0;
    while (i <= size)
    {
        if (j * 2 > size)
        {
            j--;
        }
        else if (array[j] == 0 && array[j * 2] < array[(j * 2) + 1])
        {
            array[j] = array[j * 2];
            array[j * 2] = 0;
            j = j * 2;
        }
        else if (array[j] == 0)

        {
            array[j] = array[(j * 2) + 1];
            array[(j * 2) + 1] = 0;
            j = j * 2 + 1;
        }
        i++;
    }
    for (int i = 1; i <= size; i++)
    {
        if (array[i] == 0)
        {
            if (array[size] == 0)
            {
                array[i] = array[size - 1];
            }
            else{
                array[i]=array[size];
            }
        }
    }
}


int main(){
	
	int size;
	cout<<"Enter the size of array :-";
	cin>>size;
	int arr[size];
	int data;
	for(int i=1;i<=size;i++)
	{
		cout<<"Enter data at index : "<<i<<"  ";
		cin>>data;
		arr[i]=data;
	}
	
	for(int i=1;i<=size;i++)
	{
		cout<<"Data at index : "<<i<<"   ";
		cout<<arr[i]<<endl;
		
	}
	
	minHeap(arr,size);
	for(int i=1;i<=size;i++)
	{
		cout<<arr[i]<<"	";
	}
	cout<<endl;
	maxHeap(arr,size);
	for(int i=1;i<=size;i++)
	{
		cout<<arr[i]<<"	";
	}
	cout<<endl;
    DeleteTree(arr, size);
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << "	";
    }
	
	return 0;
}
