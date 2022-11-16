#include <iostream>
#include <string>
using namespace std;

class Stack{
    private:
    int top=-1;
    int arr[5];

    public:
    Stack()
    {
        for (int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    bool isempty(){
        if(top==-1){
           return true;
        }
        else{
            return false;
        }
    }
    bool isfull(){
        if(top==4){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){
        if(isfull()){
            cout<<"STACK OVERFLOW"<<endl;
        }
        else{
            top++;
            arr[top]= data;
        }
    }
    int pop(){
        if(isempty()){
            cout<<"STACK UNDERFLOW"<<endl;
            return 0;
        }

        else{
            int poppedval=arr[top];
            arr[top]=0;
            top--;
            return poppedval;
        }
    }
    int peek(){     //to check top of stack
        if(isempty()){
            cout<<"STACK DOES NOT CONTAIN DATA"<<endl;
            return 0;
        }
        else{
            cout<<"Value at top is : "<<arr[top]<<endl;
            return 0;
        }
    }
    void display(){
        cout<<"The values is stack are: ";
        for(int i=4;i>=0;i--){
            cout<<arr[i]<<"     ";
        }
        cout<<endl;
    }

};

int main(){

    Stack s1;
    s1.pop();
    s1.push(1);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.pop();
    s1.push(7);
    s1.push(3);
    s1.display();
    s1.peek();

    return 0;
}