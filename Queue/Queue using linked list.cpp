#include <iostream>

using namespace std;

struct Node{
    int key;
    int data;
    Node* next;

    Node(){
        key=0;
        data=0;
        next=NULL;
    }

    Node(int k, int d){
        key=k;
        data=d;
        next=NULL;
    }
};

struct Queue{
    Node* front;
    Node* rear;

    Queue(){
        front=NULL;
        rear=NULL;
    }

    bool isEmpty(){
        if(rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    bool checkIfNodeExists(Node *n){
        Node* temp=front;
        bool exists=false;
        while(temp!=NULL){
            if(temp->key==n->key){
                exists=true;
                break;
            }
            temp=temp->next;
        }
        return exists;
    }

    void Enqueue(Node *n){
        if(isEmpty()){
            front=n;
            rear=n;
            cout<<"Node added successfully!"<<endl;
        }
        else if(checkIfNodeExists(n)){
            cout<<"Node already exist with key value "<<n->key<<" . Kindly enter another one."<<endl;
        }
        else{
            rear->next=n;
            rear=n;
            cout<<"Node added successfully!"<<endl;
        }
    }

    Node* Dequeue(){
        Node* temp=NULL;
        if(isEmpty()){
            cout<<"Queue already empty!"<<endl;
        }
        else{
            if(front==rear){
                temp=front;
                front=NULL;
                rear=NULL;
                return temp;
            }
            else{
                temp=front;
                front=front->next;
                return temp;
            }
        }
    }

    int Count(){
        int count=0;
        Node* temp=front;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void display(){
        if(isEmpty()){
            cout<<"Queue is empty."<<endl;
        }
        else{
            cout<<"Values in queue present are :- ";
            Node* temp=front;
            while(temp!=NULL){
                cout<<" ( "<<temp->key<<" , "<<temp->data<<" ) -->";
                temp=temp->next;
            }
        }
    }
};

int main() {
  Queue q;
  int option,key, data;
 
  do {
    cout << "What operation do you want to perform?"
	 <<"Select Option number. Enter 0 to exit." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. count()" << endl;
    cout << "5. display()" << endl;
 	 cin >> option;
 	 
	 Node * new_node = new Node();
	 
    
    switch (option) {
    case 0:
      break;
    case 1:
    	cout <<endl<< "ENQUEUEING -" <<endl;
      cout << "Enter KEY and VALUE of NODE to ENQUEUE in the Queue"<<endl;
      cin >> key;
      cin >> data;
      new_node->key = key;
      new_node->data = data;
      q.Enqueue(new_node);
      break;

    case 2:
      cout <<endl<< "DEQUEUEING - " <<endl;
      new_node = q.Dequeue();
      cout<<"Dequeued Value is: ("<<new_node->key<<","<<new_node->data<<")";
      delete new_node;
		cout<<endl;
      break;

    case 3:
    	cout <<endl<< "Is the queue empty ? " << endl;
      if (q.isEmpty())
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is NOT Empty" << endl;
      break;

    case 4:
    	cout <<endl<< "How many number of nodes ? " << endl;
      cout << "No of nodes in the Queue: " <<q.Count()<<endl;
      break;
      
    case 5:
      cout <<endl<< "Displaying the nodes - " << endl;
      q.display();
      cout << endl;
      break;
    
    default:
      cout <<endl<< "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}
