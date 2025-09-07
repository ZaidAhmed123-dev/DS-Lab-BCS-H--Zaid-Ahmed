#include<iostream>
using namespace std;

class Node{
	public:
		char data;
		Node * next;
		
		Node():data('\0'),next(nullptr){
		}
		
		Node(char val)
		{
			data = val;
			next = nullptr;
		}	
};

class Singly{
	public:
		Node * head;
		Node * tail;
		char arr[100];
		
		Singly():head(nullptr),tail(nullptr){
		}
		
		void insertAtEnd(char val)
		{
			Node * n= new Node(val);
			if(head == nullptr)
			{
				head=n;
				tail=n;
				return;
			}
			
			tail->next = n;
			tail=tail->next;
		}
		
		int count(){
			
			int len=0;
			Node * temp = head;
			while(temp!=nullptr){
				len++;
				temp=temp->next;
			}
			return len;
		}
		
		void storeInReverse(Node * temp,int i){
		
			if(temp==nullptr)
			return;
			
			storeInReverse(temp->next,i-1);
			
				arr[i]=temp->data;
		}
		
		bool checkPal(){
			bool f=true;
			storeInReverse(head,count()-1);
			Node * temp = head;

			int i=0;
		while(temp!=nullptr){
			

			if(temp->data!=arr[i])
			{
				f=false;
				break;
			}
			
			i++;
			temp=temp->next;
		}
		
		return f;
			
		}
};

int main()
{
	Singly S1;
	cout<<"fill the linked list: \n";
	
	char a;
	do{
        a=getchar();
        if (a != '\n') 
            S1.insertAtEnd(a);
	}while(a!='\n');
	
	if(S1.checkPal())
	cout<<"is a palindrome\n";
	else
	cout<<"not a palindrome\n";
		
}
