#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}  
    Node(char val) : data(val), next(nullptr) {} 
    
};

class Circular{
public:
    Node* head;
    Node* tail;

    Circular() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int val) 
	{
        Node* n = new Node(val);
        if (head == nullptr) {
            head = tail = n;
            tail->next=head;
            return;
        }
        tail->next = n;
        tail = tail->next;
        tail->next = head;
    }
		
	Node* Josephus(int k)
	{
		Node * temp = head;
		Node * prev = tail;
		
		if(head==nullptr)
		return 0;
		
		while(temp->next != temp)
		{
			for(int i = 0; i<k-1 ;i++)
			{
				prev=temp;
				temp=temp->next;
			}
			
			prev->next = temp->next;
			delete temp;
			temp = prev->next;
		}
		
		return temp;
	}
};

int main()
{
	Circular c1;
	int k,N;
	
	cout<<"Enter the number of people: \n";
	cin>>N;
	
	for(int i =0;i<N;i++)
	{
		c1.insertAtEnd(i+1);
	}
	
	
	cout<<"Enter the kth value: ";
	cin>>k;
	
	Node* n = c1.Josephus(k);
	
	cout<<"The position of the person left is: "<<n->data;
		
}
