#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* name;
    char* date;
    float marks;

public:
    Exam(const char* n, const char* d, float m) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        date = new char[strlen(d) + 1];
        strcpy(date, d);

        marks = m;
    }

    Exam(const Exam& other) {  
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        date = new char[strlen(other.date) + 1];
        strcpy(date, other.date);

        marks = other.marks;
    }
    Exam& operator=(const Exam& other) {  
        if (this != &other) {
            delete[] name;
            delete[] date;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);

            date = new char[strlen(other.date) + 1];
            strcpy(date, other.date);

            marks = other.marks;
        }
        return *this;
    }

    ~Exam() {
        cout << "Destructor called for " << (name ? name : "Unknown") << endl;
        delete[] name;
        delete[] date;
    }

    void display() const {
        cout << "Name: " << name
             << ", Date: " << date
             << ", Marks: " << marks << endl;
    }
};

int main() {
    Exam e1("Ali", "2025-08-18", 85.5);
    cout << "Object e1:" << endl;
    e1.display();

    Exam e2 = e1;  
    cout << "\nObject e2 (deep copy):" << endl;
    e2.display();

    Exam e3("Temp", "2000-01-01", 0);
    e3 = e1;  
    cout << "\nObject e3 (after assignment):" << endl;
    e3.display();

    cout << "\nExiting main..." << endl;
    return 0;
}

