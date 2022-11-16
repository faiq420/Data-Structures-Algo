#include <iostream>
using namespace std;

class node{
public:
    int key;
    int data;
    node *next;

    node(){
        key=0;
        data=0;
        next=NULL;
    }

    node(int k, int d){
        key=k;
        data=d;
        next=NULL;
    }
};

class stack
{
    public:
        node*top;

    stack(){
        top=NULL;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    bool checkIfNodeExists(node* n){
        node* temp=top;
        bool exist=false;
        while(temp!=NULL){
            if(temp->key==n->key){
                exist=true;
                break;
            }
            temp=temp->next;
        }
        return exist;
    }

    void push(node* n){
        if(top==NULL){
            top=n;
            cout<<"Node pushed successfully!!!"<<endl;
        }
        else if(checkIfNodeExists(n)){
            cout<<"Node already exist with key value "<<n->key<<" . Kindly enter another one."<<endl;
        }
        else{
            node* temp=top;
            top=n;
            n->next=temp;
            cout<<"Node pushed successfully!!!"<<endl;
        }
    }

    node* pop(){            //it is returning the address of the node popped hence it is of node type.
        if(isEmpty()){      //this syntax is used when a pointer is return instead of a variable
            cout<<"Stack underflow"<<endl;
        }
        else{
            node* temp=top;
            top=top->next;
            return temp;
        }
    }

    node* peek(){
        if(isEmpty()){      
            cout<<"Stack is empty."<<endl;
        }
        else{
            return top;
        }
    }

    int count(){
        int count=0;
        node* temp=top;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void display(){
        cout<<"Total number of nodes in stack are :- "<<count()<<endl;
        cout<<"Elements of stack are :- "<<endl;
        node*temp=top;
        while(temp!=NULL){
        cout<<" ( "<<temp->key<<" , "<<temp->data<<" ) -->";
        temp=temp->next;
        }
    }
    
};

int main() {
  stack s1;
  int option, key, data;

  do {
    cout << "What operation do you want to perform?" <<
      "Select Option number. Enter 0 to exit." << endl;
    cout << "1. push()" << endl;
    cout << "2. pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. peek()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cin >> option;

    node * new_node = new node();

    switch (option) {
    case 0:
      break;
    case 1:
      cout <<endl<< "Enter KEY and VALUE of NODE to push in the stack" <<
        endl;
      cin >> key;
      cin >> data;
      new_node -> key = key;
      new_node -> data = data;
      s1.push(new_node);
      break;
    case 2:
      cout <<endl<< "Pop Function Called - Poped Value: " << endl;
      new_node = s1.pop();
      cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")";
      delete new_node;
      cout << endl;

      break;
    case 3:
      if (s1.isEmpty())
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
        cout <<endl<< "PEEK Function Called : " << endl;
        new_node = s1.peek();
        cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")" <<
          endl;

      break;
    case 5:
      cout <<endl<< "Count Function Called: " << endl;
      cout << "No of nodes in the Stack: " << s1.count() << endl;
      break;

    case 6:
      cout <<endl<< "Display Function Called - " << endl;
      s1.display();
      cout << endl;
      break;

    default:
      cout <<endl<< "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}




