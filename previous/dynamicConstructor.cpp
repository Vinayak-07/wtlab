#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    char* name;

public:
    // Dynamic constructor
    Employee(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "Dynamic constructor called!" << endl;
    }

    void show() {
        cout << "Employee Name: " << name << endl;
    }

    ~Employee() {
        delete[] name;
    }
};

int main() {
    Employee e1("Vinayak");
    e1.show();

    return 0;
}
