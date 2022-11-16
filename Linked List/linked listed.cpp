#include <iostream>

using namespace std;

struct Node
{
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

struct singlylinkedlist
{
    Node *head;

    singlylinkedlist()
    {
        head = NULL;
    }

    singlylinkedlist(Node *n)
    {             // takes address of object n as pass by address
        head = n; 
    }

    // func to check if a node already exists using a key value
    Node *nodeExists(int k)
    {
        Node *temp = NULL; // is NULL only if key not found
        Node *ptr = head;  // address of head pointer

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {               // checks if the key of head & the key value given currently the same
                temp = ptr; // if the key is matched,temp stores it
            }
            ptr = ptr->next;
        }
        return temp;
    }

    // appending a node

    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with the key " << n->key << ". Kindly add node with another key value." << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "NODE APPENDED" << endl;
            }
            else
            {
                Node *ptr = head; // address of head pointer

                while (ptr->next != NULL)
                {
                    ptr = ptr->next; // traversing until we reach the last node
                }
                ptr->next = n;
                cout << "NODE APPENDED" << endl;
            }
        }
    }

    // Prepending a Node

    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with the key " << n->key << ". Kindly add node with another key value." << endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "NODE PREPENDED" << endl;
        }
    }

    // adding a node after a particular node

    void addNodeByKey(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "Currently a node with key value " << k << " does not exist." << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with the key " << n->key << ". Kindly add node with another key value." << endl;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node added after " << k << " with key value " << n->key << endl;
            }
        }
    }

    // deleting a node using a key

    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Linked list is already empty." << endl;
        }
        else if (head->key == k)
        {
            head = head->next;
            cout << "New head of the linked list with key value " << head->key << endl;
        }
        else
        {
            Node *temp = NULL;
            Node *prevptr = head;
            Node *currentptr = head->next;
            while (currentptr != NULL)
            {
                if (currentptr->key == k)
                {
                    temp = currentptr;
                    currentptr = NULL;
                }
                else
                {
                    prevptr = prevptr->next;
                    currentptr = currentptr->next;
                }
            }
            if (temp != NULL)
            {
                prevptr->next = currentptr->next;
                cout << "Node unlinked with key value " << k << endl;
            }
            else
            {
                cout << "No node with this key value exists." << endl;
            }
        }
    }

    // update a node using a key

    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Updated successfully." << endl;
        }
        else
        {
            cout << "No node of this key value exists." << endl;
        }
    }

    //Print the linked list

    void display(){
        if(head==NULL){
            cout<<"The linked list is empty."<<endl;
        }
        else{
            cout<<"Displaying nodes by key value"<<endl;
            Node* temp=head;
            while(temp!=NULL){
                cout<<"("<<temp->key<<" : "<<temp->data<<" )-->"<<endl;
                temp=temp->next;
            }
        }
    }
};

int main() {

  singlylinkedlist s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. addNodeByKey()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;

    cin >> option;
    Node * n1 = new Node();

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.addNodeByKey(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);

      break;
    case 6:
      s.display();

      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
