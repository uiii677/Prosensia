#include <iostream>
#include <vector>
using namespace std;

// Interface-like class
class Taxable {
public:
    virtual double calculateTax() const = 0;
    virtual ~Taxable() {}
};

// Abstract base class
class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}
    virtual void displayInfo() const = 0;
    virtual double calculateSalary() const = 0;
    virtual ~Person() {}
};

// Derived class Employee
class Employee : public Person, public Taxable {
    double basicSalary;

public:
    Employee(string n, int i, double sal)
        : Person(n, i), basicSalary(sal) {}

    void displayInfo() const override {
        cout << "Employee Name: " << name << ", ID: " << id << endl;
    }

    double calculateSalary() const override {
        return basicSalary + 0.2 * basicSalary;  // Add 20% bonus
    }

    double calculateTax() const override {
        return calculateSalary() * 0.1;  // 10% tax
    }
};

// Derived class Intern
class Intern : public Person, public Taxable {
    double stipend;

public:
    Intern(string n, int i, double st)
        : Person(n, i), stipend(st) {}

    void displayInfo() const override {
        cout << "Intern Name: " << name << ", ID: " << id << endl;
    }

    double calculateSalary() const override {
        return stipend;
    }

    double calculateTax() const override {
        return 0.05 * stipend;  // 5% tax
    }
};

int main() {
    vector<Person*> people;

    people.push_back(new Employee("Umair", 1, 50000));
    people.push_back(new Intern("Ali", 2, 10000));
    people.push_back(new Employee("Sara", 3, 60000));
    people.push_back(new Intern("Ahmed", 4, 8000));

    cout << "Company Payroll Details:\n\n";

    for (Person* p : people) {
        p->displayInfo();
        cout << "Salary: " << p->calculateSalary() << endl;

        // Dynamic cast to access Taxable interface
        Taxable* taxObj = dynamic_cast<Taxable*>(p);
        if (taxObj) {
            cout << "Tax: " << taxObj->calculateTax() << endl;
        }

        cout << "------------------------\n";
    }

    // Cleanup
    for (Person* p : people)
        delete p;

    return 0;
}

