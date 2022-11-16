#include <iostream>

using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int array[10];

    public:

    Queue(){
        front=-1;
        rear=-1;
        for(int i=0;i<10;i++){
            array[i]=0;
        }
    }

    bool isEmpty(){
        if(rear==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(rear==9){
            return true;
        }
        else{
            return false;
        }
    }

    int count(){
        return (rear-front+1);
    }

    void Enqueue(int val){
        if(isFull()){
            cout<<"Queue is already full."<<endl;
        }
        else if(isEmpty()){
            rear++;
            front++;
            array[rear]=val;
            cout<<"Value added."<<endl;
        }
        else{
            rear++;
            array[rear]=val;
            cout<<"Value added."<<endl;
        }
    }

    int Dequeue(){
        if(isEmpty()){
            cout<<"Queue is already empty."<<endl;
            return 0;
        }
        else if(front==rear){
            int x=array[front];
            array[front]=0;
            front=-1;
            rear=-1;            
            return x;
        }
        else{
            int x=array[front];
            array[front]=0;
            front++;
            return x;
        }
    }

    void display()
	{
		cout <<endl<< "Values in the Queue" << endl;
		for (int i = 0; i <10;  i++)
		{
			cout << array[i] << "  " ;
		}
	}

};
int main()
{
	Queue q1;

	int option, value;

	do
	{
		cout << "What operation do you want to perform on the queue? Select an option. Enter 0 to exit." << endl;
		cout << "1. Enqueue() " << endl;
		cout << "2. Dequeue() " << endl;
		cout << "3. isEmpty() " << endl;
		cout << "4. isFull() " << endl;
		cout << "5. count()" << endl;
		cout << "6. display() " << endl;

		cin >> option;

		switch (option)
		{
		case 0:
			return 0;
		case 1:
			cout <<endl<< "Enqueue Option - Enter a value to insert in the queue: " << endl;
			cin >> value;
			q1.Enqueue(value);
			break;
		case 2:
			cout <<endl<< "Dequeue Option - The value removed: " << q1.Dequeue() << endl;
			break;
		case 3:
			cout <<endl<< "Is the queue empty ? " << endl;
			if (q1.isEmpty())
				cout <<endl<< "Queue is Empty" << endl;
			else
				cout <<endl<< "Queue is not Empty" << endl;
			break;
		case 4:
			cout <<endl<< "Is the queue full ? " << endl;
			if (q1.isFull())
				cout <<endl<< "Queue is Full" << endl;
			else
				cout <<endl<< "Queue is not Full" << endl;
			break;
		case 5:
			cout <<endl<< "Count the total values in the queue: " << q1.count() << endl;
			break;
		case 6:
			cout <<endl<< "Display : " << endl;
			q1.display();
			cout << endl;
			break;
		default:
			cout << "Enter proper option number" << endl;
			break;
		}
	} 
	while (option != 0);
	return 0;
}

