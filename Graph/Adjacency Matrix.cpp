#include <iostream>

using namespace std;

void PrintMatrix(int MAT[10][10], int n)
{
    cout << "\n\n";
    for (int i=0 ; i<n ; i++)
        cout << "	     	   " << "[" << i << "]";
    cout << "\n\n";
    for (int i=0 ; i<n ; i++)
    {
        cout << "	" << "[" << i << "] ";
        for (int j=0 ; j<n ; j++)
        {
            cout << "	    " << MAT[i][j]<<"	";
        }
        cout << "\n\n";
    }
}
int main()
{
    int i, j, v;
    cout << "Enter the number of vertexes: ";
    cin >> v;
    int MAT[10][10];
    cout << "\n";
    
    for(i=0;i<v;i++){
    	for(j=0;j<v;j++){
    		MAT[i][j]=0;
		}
	}
    for (i=0 ; i<v-1 ; i++)
    {
        for(j=i+1 ; j<v ; j++)
        {
            cout << "Enter the weight if vertex " << i << " has edge with " << j << " , otherwise 0: ";
            cin >> MAT[i][j];
            MAT[j][i] = MAT[i][j];
        }
    }
    PrintMatrix(MAT, v);
    return 0;
}
