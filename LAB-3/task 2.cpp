#include <iostream>
using namespace std;

class Node {
public:
    int data;
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
		int count(){
			
			int len=0;
			Node * temp = head;
			while(temp!=nullptr){
				len++;
				temp=temp->next;
			}
			return len;
		}
		
		
	Node* Merge(Singly &other)
	{
		Node * tail1 = tail;
		Node * head2 = other.head;
		
		tail1->next=head2;
		
		return head;
	}
	
	void Sort(Singly &other)
	{
	
		Node* s = Merge(other);
			int len = count() + other.count();
		
		int temp;
		
		for(int i=0;i<len;i++)
		{
			Node * current = s;
			while(current != nullptr && current->next != nullptr)
			{
				if(current->data>current->next->data)
				{
					temp = current->data;
					current->data=current->next->data;
					current->next->data=temp;	
				}
				
				current=current->next;
			}
			
		}
				
		while(s!=nullptr)
		{
			cout<<s->data;
			s=s->next;
			if(s!=nullptr)
			cout<<"->";
		}
	}
};



int main() {
    Singly S1,S2;
    S1.insertAtEnd(1);
	S1.insertAtEnd(3);
	S1.insertAtEnd(5);
	S2.insertAtEnd(4);
	S2.insertAtEnd(7);
	S2.insertAtEnd(8);
	
	S1.Sort(S2);
}
