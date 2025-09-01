#include <iostream>
using namespace std;

int main() {
    int d;
    cout << "departments: "; 
	cin >> d;

    int* emp = new int[d];
    int** sal = new int*[d];

    for(int i=0;i<d;i++){
        cout << "employees in dept " << i+1 << ": ";
        cin >> emp[i];
        sal[i] = new int[emp[i]];
        for(int j=0;j<emp[i];j++){
            cout << "salary of emp " << j+1 << ": ";
            cin >> sal[i][j];
        }
    }

    for(int i=0;i<d;i++){
        int high = sal[i][0];
        for(int j=1;j<emp[i];j++)
            if(sal[i][j]>high) 
			high=sal[i][j];
        cout << "highest in dept " << i+1 << ": " << high << endl;
    }

    int bestDept = 0;
    double bestAvg = 0;
    for(int i=0;i<d;i++){
        double sum=0;
        for(int j=0;j<emp[i];j++) 
		sum+=sal[i][j];
        double avg = sum/emp[i];
        if(i==0 || avg>bestAvg)
		{
            bestAvg=avg;
            bestDept=i;
        }
    }

    cout << "dept with max avg salary: " << bestDept+1 
         << " (avg " << bestAvg << ")" << endl;

    for(int i=0;i<d;i++) delete[] sal[i];
    delete[] sal;
    delete[] emp;
}
