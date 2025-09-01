#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "students: "; cin >> n;

    int** marks = new int*[n];
    int* cnt = new int[n];

    for(int i=0;i<n;i++){
        cout << "courses of student " << i+1 << ": ";
        cin >> cnt[i];
        marks[i] = new int[cnt[i]];
        for(int j=0;j<cnt[i];j++){
            cout << "mark " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<cnt[i];j++) sum+=marks[i][j];
        double avg = (cnt[i]>0)? (double)sum/cnt[i] : 0;
        cout << "avg of student " << i+1 << ": " << avg << endl;
    }

    for(int i=0;i<n;i++) delete[] marks[i];
    delete[] marks;
    delete[] cnt;
}
