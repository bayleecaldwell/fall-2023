#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Employee {
    int employeeID;
    int hours;
    int rate;
    int pay;
};

list<Employee*> employeeList;
stack<Employee*> employeeStack;
queue<Employee*> employeeQueue;

void getEmployee(Employee*);
void displayAndDump(list<Employee*>&);
void displayAndDump(stack<Employee*>&);
void displayAndDump(queue<Employee*>&);

int main() {
    int numEmps = 0;
    Employee* empPtr = nullptr;
    
    cout << "How many employees? ";
    cin >> numEmps;
    
    cout << "Using List:" << endl;
    for (int count = 0; count < numEmps; ++count) {
        empPtr = new Employee();
        getEmployee(empPtr);
        employeeList.push_back(empPtr);
    }
    displayAndDump(employeeList);
    
    cout << "\nUsing Stack:" << endl;
    for (int count = 0; count < numEmps; ++count) {
        empPtr = new Employee();
        getEmployee(empPtr);
        employeeStack.push(empPtr);
    }
    displayAndDump(employeeStack);
    
    cout << "\nUsing Queue:" << endl;
    for (int count = 0; count < numEmps; ++count) {
        empPtr = new Employee();
        getEmployee(empPtr);
        employeeQueue.push(empPtr);
    }
    displayAndDump(employeeQueue);
    
    return 0;
}

void getEmployee(Employee* emp) {
    cout << "Enter employee number: ";
    cin >> emp->employeeID;
    cout << "How many hours did they work? ";
    cin >> emp->hours;
    cout << "What is their hourly rate? ";
    cin >> emp->rate;
    emp->pay = emp->hours * emp->rate;
}

void displayAndDump(list<Employee*>& empContainer) {
    fstream dStream("empdata_list.csv", ios::out);
    if (dStream.is_open()) {
        for (auto empPtr : empContainer) {
            dStream << empPtr->employeeID << ",";
            dStream << empPtr->hours << ",";
            dStream << empPtr->rate << ",";
            dStream << empPtr->pay << endl;
            cout << empPtr->employeeID << ",";
            cout << empPtr->hours << ",";
            cout << empPtr->rate << ",";
            cout << empPtr->pay << endl;
        }
        dStream.close();
    }
}

void displayAndDump(stack<Employee*>& empContainer) {
    fstream dStream("empdata_stack.csv", ios::out);
    if (dStream.is_open()) {
        while (!empContainer.empty()) {
            Employee* empPtr = empContainer.top();
            dStream << empPtr->employeeID << ",";
            dStream << empPtr->hours << ",";
            dStream << empPtr->rate << ",";
            dStream << empPtr->pay << endl;
            cout << empPtr->employeeID << ",";
            cout << empPtr->hours << ",";
            cout << empPtr->rate << ",";
            cout << empPtr->pay << endl;
            empContainer.pop();
            delete empPtr;
        }
        dStream.close();
    }
}

void displayAndDump(queue<Employee*>& empContainer) {
    fstream dStream("empdata_queue.csv", ios::out);
    if (dStream.is_open()) {
        while (!empContainer.empty()) {
            Employee* empPtr = empContainer.front();
            dStream << empPtr->employeeID << ",";
            dStream << empPtr->hours << ",";
            dStream << empPtr->rate << ",";
            dStream << empPtr->pay << endl;
            cout << empPtr->employeeID << ",";
            cout << empPtr->hours << ",";
            cout << empPtr->rate << ",";
            cout << empPtr->pay << endl;
            empContainer.pop();
            delete empPtr;
        }
        dStream.close();
    }
}
