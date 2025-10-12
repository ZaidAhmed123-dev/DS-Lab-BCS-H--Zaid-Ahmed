#include<iostream>
using namespace std;

class Stack{
	
	public:
		int top;
		int *arr;
		int max;
		Stack(int m):max(m){
			arr=new int[max];
			top=-1;
		}	
		
		void push(int val)
		{
			if(top >= (max-1)){
				cout<<"stack overflow";
				return;
			}
			
			arr[++top]=val;
			cout<<"\nvalue "<<val<<" pushed into stack: "<<endl;
		}
		
		void pop()
		{
			if(top < 0)
			{
				cout<<"\nstack underflow\n";
				return;
			}
			
			int x=arr[top--];
			cout<<"\nvalue "<<x<<" popped out of stack"<<endl;
		}
		
		void peek()
		{
			cout<<"\ntop value in stack is: "<<arr[top]<<endl;
		}
		
		void display()
		{
			cout<<"\ndisplaying array: \n\n";
			for(int i=0;i<top;i++)
			{
				cout<<arr[i]<<" ";
			}
		}
		
		
};

int main()
{
	Stack s(5);

	s.push(5);

	s.peek();
	s.push(6);
	s.push(7);
	s.push(8);
	s.peek();
	s.pop();

	s.display();
}
