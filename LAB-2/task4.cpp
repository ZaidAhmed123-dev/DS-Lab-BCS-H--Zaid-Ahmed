#include <iostream>
using namespace std;

int main() {
    int cat;
    cout << "categories: ";
    cin >> cat;

    int* cnt = new int[cat];
    int** books = new int*[cat];

    for (int i = 0; i < cat; i++) {
        cout << "books in category " << i + 1 << ": ";
        cin >> cnt[i];
        books[i] = new int[cnt[i]];
        for (int j = 0; j < cnt[i]; j++) {
            cout << "book id " << j + 1 << ": ";
            cin >> books[i][j];
        }
    }

    int id;
    cout << "search book id: ";
    cin >> id;

    bool found = false;
    int foundCat = -1;
    for (int i = 0; i < cat && !found; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            if (books[i][j] == id) {
                found = true;
                foundCat = i;
                break;
            }
        }
    }

    if (found) {
        cout << "book " << id << " found in category " << foundCat + 1 << endl;
    } else {
        cout << "book " << id << " not available" << endl;
    }

    for (int i = 0; i < cat; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] cnt;
}
