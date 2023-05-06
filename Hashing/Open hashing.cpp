#include <iostream>

using namespace std;

struct OpenHash
{
    int data;
    OpenHash *next;
};

const int HS = 10;
OpenHash *HT[HS];

void addKey(int value)
{
    int key = value % HS;
    OpenHash *ptr = new OpenHash();
    ptr->data = value;
    ptr->next = NULL;
    if (HT[key] == NULL)
    {
        HT[key] = ptr;
    }
    else
    {
        OpenHash *root = new OpenHash();
        root = HT[key];
        while (root->next != NULL)
        {
            root = root->next;
        }
        root->next = ptr;
    }
}

void getFromIndex(int index)
{
    OpenHash *root = new OpenHash();
    root = HT[index];
    int count = 1;
    cout << "Values at index : " << index << " :- " << endl;
    while (root != NULL)
    {
        cout << "     Value " << root->data << " at  position :  " << count << endl;
        count++;
        root = root->next;
    }
}

void getPosition(int value)
{
    int key = value % HS;
    int count = 1;
    if (HT[key]->data == value)
    {
        cout << value << "at position : " << count << endl;
    }
    else
    {
        OpenHash *root = new OpenHash();
        root = HT[key];
        while (root != NULL)
        {
            if (root->data == value)
            {
                cout << value << " at position : " << count << endl;
                break;
            }
            count++;
            root = root->next;
        }
        if(root==NULL){
            cout<<value<<" not found."<<endl;
        }
    }
}

void display()
{
    OpenHash *root = new OpenHash();
    for (int i = 0; i < HS; i++)
    {
        if (HT[i] == NULL)
        {
            continue;
        }
        else
        {
            root = HT[i];
            cout << "For index : " << i << " :-  ";
            while (root->next != NULL)
            {
                cout << root->data << "  ";
                root = root->next;
            }
            cout << root->data << endl;
        }
    }
}

int main()
{
    for (int i = 0; i < HS; i++)
    {
        HT[i] == NULL;
    }
    addKey(11);
    addKey(12);
    addKey(13);
    addKey(23);
    addKey(22);
    addKey(44);
    addKey(54);
    addKey(64);
    addKey(1664);
    display();
    getFromIndex(2);
    getPosition(54);
    getPosition(3264);

    return 0;
}
