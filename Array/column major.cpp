#include <iostream>
using namespace std;
//Calculating Column Major of Two dimensional array through the slot formula
void ColumnMajor(){
    int SizeofData=4;
  
           
    int Row, Column;
    cout << "Enter number of rows = "<<endl;
    cin >> Row;
    cout << "Enter number of columns = "<<endl;
    cin >> Column;
    int Data[Row][Column];
     int TotalElement=Row*Column;
     cout<<"TOTAL ELEMENTS :- "<<TotalElement<<endl;
    for (int j = 0; j < Column; j++)
    {
        for (int i = 0; i<Row; i++)
        {
            cout<<"Enter the element of row " <<i+1<< " column  "<<j+1<<endl;
            cin >> Data[j][i];
        }
    }
    for (int j = 0; j < Column; j++)
    {
        for (int i = 0; i<Row; i++)
        {
            cout << "Array[" << i << "][" << j << "] =" <<
           Data[j][i] << endl;
        }
        
    }
    cout<<"Total Memory located "<<TotalElement*SizeofData<<endl;

 	int *BaseAddress=&Data[0][0];
  	int AddressData[Row][Column];
    int I[TotalElement];
  	int S[TotalElement];
  
    int  Slot=0;
    for (int i = 0; i <TotalElement; i++)
    {
        int Product=1;
        for(int s=i+1;s<=TotalElement;s++)
		{
        	Product=Product*S[s];
      	}
        Slot=Slot+I[i]*Product;
    }
    int k=0;
    while(k<TotalElement)
	{
      for(int j=0;j<Column;j++)
        {
          	for(int i=0;i<Row;i++)
		  	{

	         cout<<"Address of Data through slot formula: "<< Data[j][i]<< " ";		
	        AddressData[j][i]=*BaseAddress+Slot*SizeofData;
	          cout<<AddressData[j][i]<<endl;
	          Slot++;
	          k++;
        	}
        }
    }

}



  
int main(){
	
    ColumnMajor();
    											
    return 0;
} 
