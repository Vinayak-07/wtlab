Exp 2)
// Online C++ compiler to run C++ program online
/* basic da it, net salary and prnnt data members 
 allowance = 0.2*basic
 ioncom tax = 0.3 * (allowance plus basic)
 net salary
 */

#include <iostream>
using namespace std;
class Employee{
    private:
        int employeeNumber;
        string employeeName;
        float allowance;
        float da;
        float basic;
        float incomTax;
        float netSalary;
    public:
        void getData(){
            cout<<"enter Name, ID, Basic \n";
            cin>>employeeName;
            cin>>employeeNumber;
            cin>>basic;
        }
        void calcData(){
            allowance = 0.2 * basic;
            incomTax = 0.3 * (basic+allowance);
            netSalary = (allowance + basic) - incomTax; 
        }
        void Display(){
            cout<<"-----Details-----"<<endl;
            cout<<"Name: "<<employeeName<<endl;
            cout<<"ID: "<<employeeNumber<<endl;
            cout<<"Basic: "<<basic<<endl;
            cout<<"Allowance: "<<allowance<<endl;
            cout<<"Incom tax: "<<incomTax<<endl;
            cout<<"Net salary: "<<netSalary<<endl;
            
        }
        
};


int main() {
    Employee me;
    me.getData();
    me.calcData();
    me.Display();
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeNumber;
    string employeeName;
    float allowance;
    float da;
    float basic;
    float incomTax;
    float netSalary;
    int score;
    string leaveDates[100]; 
    int leaveCount;         

public:
    
    Employee() {
        leaveCount = 0;
    }

    void getData() {
        cout << "Enter Name, ID, Basic Salary: \n";
        cin >> employeeName;
        cin >> employeeNumber;
        cin >> basic;
    }

    void calcData() {
        allowance = 0.2 * basic;
        incomTax = 0.3 * (basic + allowance);
        netSalary = (allowance + basic) - incomTax; 
    }

    void Display() {
        cout << "\n----- Employee Details -----\n";
        cout << "Name: " << employeeName << endl;
        cout << "ID: " << employeeNumber << endl;
        cout << "Basic: " << basic << endl;
        cout << "Allowance: " << allowance << endl;
        cout << "Income Tax: " << incomTax << endl;
        cout << "Net Salary: " << netSalary << endl;
        cout << "----------------------------\n";
    }

    void leave() {
        if (leaveCount < 100) {
            cout << "Enter date you want to take leave on (e.g., DD/MM/YY): \n";
            cin >> leaveDates[leaveCount];
            leaveCount++;
            cout << "Leave applied successfully!\n";
        } else {
            cout << "Leave record is full!\n";
        }
    }

    void showLeaves() {
        cout << "\n----- Applied Leaves -----\n";
        if (leaveCount == 0) {
            cout << "No leaves applied yet.\n";
        } else {
            for (int i = 0; i < leaveCount; i++) {
                cout << i + 1 << ". Date: " << leaveDates[i] << endl;
            }
        }
        cout << "--------------------------\n";
    }
};

int main() {
    Employee me;
    int choice;

    me.getData();
    me.calcData();

    
    while (true) {
        cout << "\n========= EMPLOYEE MENU =========\n";
        cout << "1. Display Employee Details\n";
        cout << "2. Apply for Leave\n";
        cout << "3. View Applied Leaves\n";
        cout << "4. Re-calculate / Update Salary Data\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                me.Display();
                break;
            case 2:
                me.leave();
                break;
            case 3:
                me.showLeaves();
                break;
            case 4:
                me.getData();
                me.calcData();
                cout << "Data updated successfully!\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
