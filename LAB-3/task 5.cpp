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

    void insertAtEnd(char val) 
	{
        Node* n = new Node(val);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = tail->next;
    }
	
};

class dNode{
	
public:
	char data;
    dNode* next;
    dNode* prev;

    dNode() : data(NULL), next(nullptr) , prev(nullptr) {}  
    dNode(char val) : data(val), next(nullptr), prev(nullptr) {} 
    
};

class Doubly{
	public:
		dNode* head;
		dNode* tail;
		
		Doubly() : head(nullptr), tail(nullptr) {}
		
	void insertAtEnd(char val) 
	{
        dNode* n = new dNode(val);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        
        tail->next = n;
        n->prev = tail;
        tail = tail->next;
    }
    
	void display() 
	{
        dNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
            if (temp != nullptr) cout << " <-> ";
        }
        cout << endl;
    }
	
	void SinglyToDoubly(Singly &S)
	{
		Node * s= S.head;
		while(s != nullptr)
		{
			this->insertAtEnd(s->data);
			s = s->next;
		}
	}		
	
};

class Circular{
public:
    Node* head;
    Node* tail;

    Circular() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(char val) 
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
    
    void SinglyToCircular(Singly &S)
	{
		Node * x= S.head;
		while(x != nullptr)
		{
			this->insertAtEnd(x->data);
			x = x->next;
		}
	}
	
	void display() {
        if (head == nullptr) 
		return;
        
		Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);
        cout << " -> (back to head)" << endl;
    }
	
};

int main(){
	
	Singly s1;
	Doubly d1;
	Circular c1;
	
	cout<<"fill the linked list: \n";
	
	char a;
	do{
        a=getchar();
        if (a != '\n') 
            s1.insertAtEnd(a);
	}while(a!='\n');
	
	cout<<"\nSingly to Doubly:\n";
	
	d1.SinglyToDoubly(s1);
	d1.display();
	
	cout<<"\nSingly to circular:\n";
	c1.SinglyToCircular(s1);
	c1.display();
}
		
		
