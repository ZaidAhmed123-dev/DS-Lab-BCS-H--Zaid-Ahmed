#include <iostream>
using namespace std;

void printNumbers(int n) {
    if(n==0)
        return;
    cout << n << " ";
    printNumbers(n-1);
}

void functionA(int n);
void functionB(int n);

void functionA(int n) {
    if(n==0) 
        return;
    cout << "A:" << n << " ";
    functionB(n-1);
}

void functionB(int n) {
    if(n==0) 
        return;
    cout << "B:" << n << " ";
    functionA(n-1);
}

int main() {
    cout << "Direct Recursion: ";
    printNumbers(5);

    cout << "\nIndirect Recursion: ";
    functionA(5);

    return 0;
}
