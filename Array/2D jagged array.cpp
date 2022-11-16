#include <stdlib.h>
#include <iostream>
// #include <string>

using namespace std;

int main()
{
	int rows;
	cout<<"Enter the number of rows :- ";
	cin>>rows;
	int *cols= new int[rows];		//array to store number of columns
	int **array =new int*[rows];		//jagged array

	for(int i=0;i<rows;i++){
		cout<<"Enter number of columns in row "<<i+1<<" :- ";
		cin>>cols[i];
		array[i]=new int [cols[i]]; 
	}
	
	//inputting values
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols[i];j++){
			cout<<"Enter the data value at row "<<i+1<<" and column "<<j+1<<" :- ";
			cin>>array[i][j];
		}
	}
	
	//outputting values
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols[i];j++){
			cout<<array[i][j]<<"  ";
		}
		cout<<"\n";
	}
	
	delete[] array;
	array=NULL;
    return 0;








}
