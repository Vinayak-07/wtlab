#include <iostream>
#include <string.h>

using namespace std;

class abc
{
    private:
    string nm;
    int age;

    public:
    abc(){}
    abc(string x, int y);
    void get(){
        cout<<"enter your name";
        cin>>nm;
        cout<<"enter your age"<<endl;
        cin>>age;
    }
    void display(){
        cout<<nm<<endl;
        cout<<age;
    }
};

abc::abc(string x, int y)
{
    nm = x;
    age  = y;
}

int main() 
{
    abc a;
    abc m = abc("\ncomputer",2000);
    a.get();
    a.display();
    m.display();
    return 0;

}
