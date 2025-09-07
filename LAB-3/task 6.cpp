#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int val) : data(val), next(nullptr), child(nullptr) {}
};

class MultiLevel {
public:
    Node* head;
    Node* tail;

    MultiLevel() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int val) 
    {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = tail->next;
    }

    void insertChild(Node* parent, int val) 
    {
        if (parent == nullptr) 
            return;
        Node* n = new Node(val);
        if (parent->child == nullptr) {
            parent->child = n;
            return;
        }
        Node* temp = parent->child;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void flatten() 
    {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->child != nullptr) {
                Node* childList = temp->child;
                Node* nextNode = temp->next;

                temp->next = childList;

                Node* last = childList;
                while (last->next != nullptr) {
                    last = last->next;
                }

                last->next = nextNode;

                temp->child = nullptr;
            }
            temp = temp->next;
        }
    }

    void display() 
    {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next;
            if (temp != nullptr) 
                cout << " -> ";
        }
        cout << endl;
    }
};

int main()
{
    MultiLevel M;

    M.insertAtEnd(1);
    M.insertAtEnd(2);
    M.insertAtEnd(3);

    M.insertChild(M.head->next, 4);
    M.insertChild(M.head->next, 5);

    cout<<"Original multilevel list :\n";
    cout<<"Main list: 1 -> 2 -> 3\n";
    cout<<"Child of 2: 4 -> 5\n\n";

    cout<<"Flattened list:\n";
    M.flatten();
    M.display();
}
