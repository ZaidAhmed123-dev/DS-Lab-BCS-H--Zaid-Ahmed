#include <iostream>
using namespace std;

class Box {
private:
    int* num;

public:
    Box(int n = 0) {
        num = new int(n);
    }

    Box(const Box& other) {
        num = new int(*other.num);
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete num;
            num = new int(*other.num);
        }
        return *this;
    }

    ~Box() {
        delete num;
    }

    void set(int n) { *num = n; }
    int get() const { return *num; }

    void show(const string& name) const {
        cout << name << " -> Value: " << *num 
             << " | Address: " << num << endl;
    }
};

int main() {
    cout << "Deep Copy Demo " << endl;
    Box b1(10);
    b1.show("b1");

    Box b2 = b1;
    b2.show("b2");

    b2.set(20);
    cout << "\nAfter changing b2:" << endl;
    b1.show("b1");
    b2.show("b2");

    cout << "\n=Assignment Demo " << endl;
    Box b3;
    b3 = b1;
    b3.show("b3");

    b3.set(30);
    cout << "\nAfter changing b3:" << endl;
    b1.show("b1");
    b3.show("b3");

    cout << "\n=== Shallow Copy Demo (Manual) ===" << endl;
    int* shared = new int(500);
    Box f1;
    Box f2;
    *(int**)(&f1) = shared;
    *(int**)(&f2) = shared;

    cout << "f1 - " << *shared << " at " << shared << endl;
    cout << "f2 - " << *shared << " at " << shared << endl;
    delete shared;

    return 0;
}

