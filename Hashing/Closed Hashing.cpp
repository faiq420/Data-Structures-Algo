#include <iostream>
using namespace std;

class ClosedHash
{
private:
    int *HT;
    int HS;
    int HI;

public:
    ClosedHash(int size)
    {
        this->HS = size;
        HT = new int[HS];
        for (int i = 0; i < HS; i++)
        {
            HT[i] = -1;
        }
    }
    void AddNode(int key)
    {
        HI = key % HS;
        if (HT[HI] == -1)
        {
            HT[HI] = key;
        }
        else
        {
            // linear probing
            int i = HI;
            int count = 0;
            while (HT[i] != -1)
            {
                count++;
                if (i == (HS - 1))
                {
                    i = (i + 1) % HS;
                }
                else
                {
                    i++;
                }
                //If the array is full then on inserting it will through error
                if (count==HS)
                {   
                    cout<<"Array is full, cannot insert number "<<key<<endl;
                    break; 
                }
                
            }
            if (HT[i] == -1)
            {
                HT[i] = key;
            }
        }
    }
    void DisplayHashT()
    {
        for (int i = 0; i < HS; i++)
        {
            cout << i << ": " << HT[i] << endl;
        }
    }
    void Search(int key)
    {
        HI = key % HS;
        if (HT[HI] == key)
        {
            cout << "Number found at index " << HI;
        }
        else
        {
            int i = HI;
            int count = 0;
            while (HT[i] != key || HT[i]==-1)
            {
                count++;
                if (i == (HS - 1))
                {
                    i = (i + 1) % HS;
                }
                else
                {
                    i++;
                }
                if (count == HS)
                {
                    break;
                }
            }
            if (HT[i] == key)
            {
                cout << "Found at index: " << i<<endl;
            }
            else
            {
                cout << "Number not found"<<endl;
            }
            
        }
    }
    ~ClosedHash(){
        delete[] HT;     
    }
};
int main()
{
    ClosedHash obj(10);
    obj.AddNode(100);
    obj.AddNode(12);
    obj.AddNode(33);
    obj.AddNode(11);
    obj.AddNode(21);
    obj.AddNode(26);
    obj.AddNode(54);
    obj.AddNode(48);
    obj.AddNode(65);
    obj.AddNode(69);
    obj.AddNode(28);
    obj.AddNode(18);
    obj.DisplayHashT();
    obj.Search(28);
    obj.Search(18);
    return 0;
}
