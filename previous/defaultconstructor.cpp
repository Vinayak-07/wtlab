```
#include <iostream>
using namespace std;

class Default_constructor{
    public:
    int a,b;
    Default_constructor(){
        a = 100;
        b = 200;
    }
};

int main() 
{
    Default_constructor con;
    cout<< "value of a "<< con.a<<endl;
    cout<<"value of b "<<con.b;
    return 0;

}
```
