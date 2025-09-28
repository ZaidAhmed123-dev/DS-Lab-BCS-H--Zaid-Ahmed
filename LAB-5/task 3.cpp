#include <iostream>
using namespace std;

int sumTail(int n, int total=0) {
    if(n==0)
        return total;
    return sumTail(n-1, total+n);
}

int sumNonTail(int n) {
    if(n==0)
        return 0;
    return n + sumNonTail(n-1);
}

int main() {
    int x=5;
    cout << "Tail Recursion: " << sumTail(x) << endl;
    cout << "Non-Tail Recursion: " << sumNonTail(x) << endl;
    return 0;
}
