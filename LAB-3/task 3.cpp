#include<iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node() : data(NULL), next(nullptr) {}  
    Node(char val) : data(val), next(nullptr) {} 
    
};

class Singly {
public:
    Node* head;
    Node* tail;

    Singly() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(char val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = tail->next;
    	}
		
		void Group(Node * n,Singly &other, int k,int &x){
		
				
			if(x>=k || n == nullptr)
			return;
			
			x++;
			Group(n->next,other,k,x);
			other.insertAtEnd(n->data);

		}
		
		void ReverseInGroups(Singly &other)
		{
			int k;
			cout<<"Enter size of groups to reverse in: ";
			cin>>k;
			
			Node * temp = head;
			
			while(temp != nullptr)
			{
				int x=0;
				Group(temp,other,k,x);
				
				for(int i=0;i<k && temp != nullptr;i++)
				{
					temp=temp->next;
				}
				
			}
			
			Node * o = other.head;
			
		cout<<"\nReveresed in groups of "<<k<<":\n";
		
		while(o!=nullptr)
		{
			cout<<o->data;
			o=o->next;
			if(o!=nullptr)
			cout<<"->";
		}
		
		}
	};
	
int main()
{
	Singly S1,S2;
	
	cout<<"fill the linked list: \n";
	
	char a;
	do{
        a=getchar();
        if (a != '\n') 
            S1.insertAtEnd(a);
	}while(a!='\n');
	
	
	
	S1.ReverseInGroups(S2);
}		
