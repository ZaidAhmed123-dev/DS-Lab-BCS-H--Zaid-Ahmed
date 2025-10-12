#include <iostream>
#include <string>
using namespace std;

class Node{

public:
	string data;
	Node* next;
	
	Node(string val):data(val){
		next=nullptr;
	}
};

class Stack{
	public:
		Node* top;
		Node* bottom;
		
		Stack(){
			top=nullptr;
			bottom=nullptr;
		}
		
		void push(string val)
		{
			Node* n=new Node(val);
			
			if(top==nullptr)
			{
				top=n;
				bottom=n;
				cout<<"Visited: "<<val<<endl;
				return;
			}
			
			n->next=top;
			top=n;
			cout<<"Visited: "<<val<<endl;
		}
		
		void pop(){
			if(top==nullptr)
			{
				cout<<"No previous pages to go back to!"<<endl;
				return;
			}
			
			cout<<"Going back from: "<<top->data<<endl;
			Node* temp=top;
			top=top->next;
			delete temp;
			
			if(top==nullptr)
				bottom=nullptr;
		}
		
		void peek(){
			if(top==nullptr)
			{
				cout<<"No pages visited yet."<<endl;
				return;
			}
			
			cout<<"Current page: "<<top->data<<endl;
		}
		
		void display(){
			if(top==nullptr)
			{
				cout<<"No browsing history."<<endl;
				return;
			}
			
			cout<<"Browsing history (most recent first): ";
			Node* temp=top;
			while(temp!=nullptr)
			{
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"NULL"<<endl;
		}
};

int main(){
	Stack history;
	int choice;
	string page;
	
	do{
		cout<<"\n--- Browser History Menu ---"<<endl;
		cout<<"1. Visit new page"<<endl;
		cout<<"2. Go back"<<endl;
		cout<<"3. Show current page"<<endl;
		cout<<"4. Show all history"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				cout<<"Enter page name: ";
				cin>>page;
				history.push(page);
				break;
				
			case 2:
				history.pop();
				break;
				
			case 3:
				history.peek();
				break;
				
			case 4:
				history.display();
				break;
				
			case 5:
				cout<<"Exiting browser simulation..."<<endl;
				break;
				
			default:
				cout<<"Invalid choice!"<<endl;
		}
		
	}while(choice!=5);
	
	return 0;
}
