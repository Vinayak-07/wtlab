#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    // Normal constructor
    Box(int l) {
        length = l;
    }

    // Copy constructor
    Box(const Box& b) {
        length = b.length;
        cout << "Copy constructor called!" << endl;
    }

    void show() {
        cout << "Length: " << length << endl;
    }
};

int main() {
    Box b1(10);
    Box b2 = b1; // Copy constructor invoked

    b1.show();
    b2.show();

    return 0;
}
