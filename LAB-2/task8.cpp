#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "days: ";
    cin >> n;

    cout << "times per day: ";
    cin >> m;

    double** temp = new double*[n];
    for (int i = 0; i < n; i++) {
        temp[i] = new double[m];
        for (int j = 0; j < m; j++) {
            cout << "temp day " << i + 1 << " time " << j + 1 << ": ";
            cin >> temp[i][j];
        }
    }
	cout<<endl;
    double* avg = new double[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < m; j++) {
            sum += temp[i][j];
        }
        avg[i] = sum / m;
        cout << "avg day " << i + 1 << ": " << avg[i] << endl;
    }

    int hot = 0, cold = 0;
    for (int i = 1; i < n; i++) {
        if (avg[i] > avg[hot]) hot = i;
        if (avg[i] < avg[cold]) cold = i;
    }

    cout << "\nhottest day: " << hot + 1 << endl;
    cout << "avg temp: " << avg[hot] << endl;

    cout << "coldest day: " << cold + 1 << endl;
    cout << "avg temp: " << avg[cold] << endl;

    for (int i = 0; i < n; i++) {
        delete[] temp[i];
    }
    delete[] temp;
    delete[] avg;
}
