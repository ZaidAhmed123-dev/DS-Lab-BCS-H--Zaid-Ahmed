#include <iostream>
using namespace std;

class SafePtr {
    int* p;
public:
    SafePtr() { p = new int; }
    ~SafePtr() { delete p; }
    void setValue(int v) { *p = v; }
    int getValue() { return *p; }
    int* release() {
        int* tmp = p;
        p = nullptr;
        return tmp;
    }
};

int main() {
    const int n=5;
    SafePtr* arr = new SafePtr[n];

    for(int i=0;i<n;i++){
        int m;
        cout << "student " << i+1 << " marks : ";
        cin >> m;
        arr[i].setValue(m);
    }

    cout << "marks: ";
    for(int i=0;i<n;i++) cout << arr[i].getValue() << " ";
    cout << endl;

    delete[] arr;
}
