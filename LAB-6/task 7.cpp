#include <iostream>
using namespace std;

class Process{
	public:
	int id;
	int priority;
	
	Process(){}
	Process(int i,int p){
		id=i;
		priority=p;
	}
};

class Queue{
	public:
		int front,rear,size;
		Process *arr;
		
		Queue(int s){
			size=s;
			arr=new Process[size];
			front=rear=-1;
		}
		
		bool isEmpty(){
			return front==-1;
		}
		
		bool isFull(){
			return (rear+1)==size;
		}
		
		void enqueue(Process p){
			if(isFull()){
				cout<<"Queue Overflow!"<<endl;
				return;
			}
			if(front==-1) front=0;
			arr[++rear]=p;
		}
		
		Process dequeue(){
			if(isEmpty()){
				cout<<"Queue Underflow!"<<endl;
				return Process(-1,-1);
			}
			Process temp=arr[front];
			if(front==rear)
				front=rear=-1;
			else
				front++;
			return temp;
		}
		
		void display(){
			if(isEmpty()){
				cout<<"Queue is empty!"<<endl;
				return;
			}
			cout<<"Arrival Queue (Front to Rear): ";
			for(int i=front;i<=rear;i++)
				cout<<"[P"<<arr[i].id<<",Pr="<<arr[i].priority<<"] ";
			cout<<endl;
		}
};

class Stack{
	public:
		int top,size;
		Process *arr;
		
		Stack(int s){
			size=s;
			arr=new Process[size];
			top=-1;
		}
		
		bool isEmpty(){
			return top==-1;
		}
		
		bool isFull(){
			return top==size-1;
		}
		
		void push(Process p){
			if(isFull()){
				cout<<"Stack Overflow!"<<endl;
				return;
			}
			arr[++top]=p;
		}
		
		Process pop(){
			if(isEmpty()){
				cout<<"Stack Underflow!"<<endl;
				return Process(-1,-1);
			}
			return arr[top--];
		}
		
		void display(){
			if(isEmpty()){
				cout<<"Stack is empty!"<<endl;
				return;
			}
			cout<<"Execution Stack (Top to Bottom): ";
			for(int i=top;i>=0;i--)
				cout<<"[P"<<arr[i].id<<",Pr="<<arr[i].priority<<"] ";
			cout<<endl;
		}
};

int main(){
	int n;
	cout<<"Enter number of processes: ";
	cin>>n;
	
	Queue q(n);
	Stack s(n);
	
	for(int i=0;i<n;i++){
		int id,pr;
		cout<<"Enter Process ID and Priority: ";
		cin>>id>>pr;
		Process p(id,pr);
		q.enqueue(p);
	}
	
	cout<<endl;
	q.display();
	
	cout<<endl<<"Moving processes to execution stack (higher priority first)..."<<endl;
	
	while(!q.isEmpty()){
		Process p=q.dequeue();

		int pos=s.top;
		while(pos>=0 && s.arr[pos].priority < p.priority){
			s.arr[pos+1]=s.arr[pos];
			pos--;
		}
		s.arr[pos+1]=p;
		s.top++;
	}
	
	s.display();
	
	cout<<endl<<"Executing processes in LIFO order:"<<endl;
	while(!s.isEmpty()){
		Process run=s.pop();
		cout<<"Executing Process P"<<run.id<<" with Priority "<<run.priority<<endl;
	}
	
	return 0;
}
