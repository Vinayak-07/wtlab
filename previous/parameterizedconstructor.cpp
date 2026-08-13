#include <iostream>
using namespace std;

class Integer
{
    public:
    int m,n;
    Integer(int x, int y);
    void display(){
        cout<<"m="<<m;
        cout<<"n="<<n;
    }
};

Integer::Integer(int x, int y)
{
    m = x;
    n = y;

}

int main() 
{
    Integer int1(0,100);
    Integer int2=Integer(25,75);
    cout <<"\n object 1: "<< endl;
    int1.display();
    cout <<"\n object 2: "<< endl;
    int2.display();
    
    return 0;

}
