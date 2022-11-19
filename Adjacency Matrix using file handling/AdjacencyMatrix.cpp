#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
void Outdegree(int * array,int size)
{
    int OD[size];
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (*((array)+i*size+j)!=0)
            {
                count++;
            }
            
        }
        OD[i]=count;
    }
    cout<<"Outdegrees are: ";
    for (int i = 0; i < size; i++)
    {
        cout<<OD[i]<<" ";
    }
    cout<<endl;
}
void Indegree(int * array,int size)
{
    int IN[size];
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (*((array)+j*size+i)!=0)
            {
                count++;
            }
            
        }
        IN[i]=count;
    }
    cout<<"Indegrees are : ";
    for (int i = 0; i < size; i++)
    {
        cout<<IN[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    ifstream Myfile;
    Myfile.open("graph.txt");
    string ignoreline;
    getline(Myfile, ignoreline);
    string veredge;
    getline(Myfile, veredge);
    char vevalues[veredge.length()];
    strcpy(vevalues, veredge.c_str());
    int const vertices = atoi(strtok(vevalues, " "));
    int const edges = atoi(strtok(NULL, ""));
    int arr[vertices][vertices];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            arr[i][j]=0;
        }   
    }
    while (!Myfile.eof())
    {
        string data;
        getline(Myfile, data);
        char chardata[data.length()];
        strcpy(chardata, data.c_str());
        int X = atoi(strtok(chardata, ","));
        int Y = atoi(strtok(NULL, ","));
        int value = atoi(strtok(NULL, ""));
        if (value == 0)
        {
            arr[X][Y] = 1;
        }
        else{
            arr[X][Y] = value;
        }
    }

    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl<<"Vertices are  : ";
    for(int i=0;i<vertices;i++){
        cout<<i<<" ";
    }
    cout<<endl;

    Outdegree((int *)arr,vertices);
    Indegree((int *)arr,vertices);

}
