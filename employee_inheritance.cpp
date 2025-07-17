#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}

    virtual void display() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
    double bonus;

public:
    Manager(string n, int i, double s, double b) : Employee(n, i, s), bonus(b) {}

    void display() override {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};

class Developer : public Employee {
    string language;

public:
    Developer(string n, int i, double s, string lang) : Employee(n, i, s), language(lang) {}

    void display() override {
        Employee::display();
        cout << "Programming Language: " << language << endl;
    }
};

int main() {
    Employee* staff[3];

    staff[0] = new Manager("Ali", 101, 80000, 15000);
    staff[1] = new Developer("Sara", 102, 70000, "C++");
    staff[2] = new Developer("Ahmed", 103, 75000, "Python");

    for (int i = 0; i < 3; i++) {
        cout << "----- Employee " << i + 1 << " Details -----" << endl;
        staff[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete staff[i];
    }

    return 0;
}

