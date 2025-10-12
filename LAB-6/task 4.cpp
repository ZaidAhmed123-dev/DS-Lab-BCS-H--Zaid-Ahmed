#include <iostream>
using namespace std;

class CircularQueue{
	public:
		int front;
		int rear;
		int size;
		int *arr;
		
		CircularQueue(int s){
			size=s;
			arr=new int[size];
			front=-1;
			rear=-1;
		}
		
		bool isEmpty(){
			if(front==-1)
				return true;
			return false;
		}
		
		bool isFull(){
			if((rear+1)%size==front)
				return true;
			return false;
		}
		
		void enqueue(int val){
			if(isFull()){
				cout<<"Queue Overflow! Cannot insert "<<val<<endl;
				return;
			}
			
			if(front==-1)
				front=0;
				
			rear=(rear+1)%size;
			arr[rear]=val;
			cout<<val<<" enqueued into the queue."<<endl;
		}
		
		void dequeue(){
			if(isEmpty()){
				cout<<"Queue Underflow! Nothing to dequeue."<<endl;
				return;
			}
			
			cout<<arr[front]<<" dequeued from the queue."<<endl;
			
			if(front==rear){
				front=-1;
				rear=-1;
			}
			else
				front=(front+1)%size;
		}
		
		void display(){
			if(isEmpty()){
				cout<<"Queue is empty."<<endl;
				return;
			}
			
			cout<<"Queue contents: ";
			int i=front;
			while(true){
				cout<<arr[i]<<" ";
				if(i==rear)
					break;
				i=(i+1)%size;
			}
			cout<<endl;
		}
};

int main(){
	int n;
	cout<<"Enter queue size: ";
	cin>>n;
	
	CircularQueue q(n);
	int choice,val;
	
	do{
		cout<<"\n Circular Queue Menu\n"<<endl;
		cout<<"1. Enqueue"<<endl;
		cout<<"2. Dequeue"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"4. Check Empty/Full"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter value: ";
				cin>>val;
				q.enqueue(val);
				break;
				
			case 2:
				q.dequeue();
				break;
				
			case 3:
				q.display();
				break;
				
			case 4:
				if(q.isEmpty())
					cout<<"Queue is empty."<<endl;
				else if(q.isFull())
					cout<<"Queue is full."<<endl;
				else
					cout<<"Queue has space."<<endl;
				break;
				
			case 5:
				cout<<"Exiting"<<endl;
				break;
				
			default:
				cout<<"Invalid choice!"<<endl;
		}
		
	}while(choice!=5);
	
	return 0;
}
