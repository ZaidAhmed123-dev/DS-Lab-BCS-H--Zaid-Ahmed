#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "months: "; 
	cin >> n;

    double* exp = new double[n];
    for(int i=0;i<n;i++){
        cout << "expense month " << i+1 << ": ";
        cin >> exp[i];
    }

    char more;
    cout << "add more months? (y/n): "; 
	cin >> more;
    if(more=='y'||more=='Y'){
        int extra;
        cout << "extra months: "; 
		cin >> extra;
        double* temp = new double[n+extra];
        
        for(int i=0;i<n;i++) 
		temp[i]=exp[i];
		
        for(int i=0;i<extra;i++){
            cout << "expense month " << n+i+1 << ": ";
            cin >> temp[n+i];
        }
        
        delete[] exp;
        exp=temp;
        n+=extra;
    }

    double sum=0;
    for(int i=0;i<n;i++) 
	sum+=exp[i];
    cout << "total: " << sum << endl;
    cout << "avg: " << sum/n << endl;

    delete[] exp;
}
