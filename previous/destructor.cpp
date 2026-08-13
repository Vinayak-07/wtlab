#include <iostream>
using namespace std;

class Demo {
public:
    Demo() {
        cout << "Constructor called!" << endl;
    }

    ~Demo() {
        cout << "Destructor called! Object destroyed." << endl;
    }
};

int main() {
    Demo d1; // Constructor runs

    cout << "Inside main function." << endl;

    return 0; // Destructor runs automatically here
}
