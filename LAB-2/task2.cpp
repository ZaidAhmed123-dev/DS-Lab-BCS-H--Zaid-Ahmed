#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "benches: "; cin >> r;
    cout << "seats: "; cin >> c;

    int** seat = new int*[r];
    for(int i=0;i<r;i++){
        seat[i] = new int[c];
        for(int j=0;j<c;j++) 
		seat[i][j]=0;
    }

    int x, y;
    char ch='y';
    while(ch=='y'||ch=='Y'){
        cout << "enter row and seat no: "; 
		cin >> x >> y;
        if(x>=0 && x<r && y>=0 && y<c) seat[x][y]=1;
        cout << "more? (y/n): ";
		cin >> ch;
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++) 
		cout << seat[i][j] << " ";
        cout << endl;
    }

    for(int i=0;i<r;i++) delete[] seat[i];
    delete[] seat;
}
