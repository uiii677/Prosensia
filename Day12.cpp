#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    float salary;
};

// Function to load employees from file into a vector
vector<Employee> loadEmployees() {
    vector<Employee> employees;
    ifstream file("employees.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Employee emp;
        string salaryStr;
        getline(ss, line, ','); emp.id = stoi(line);
        getline(ss, emp.name, ',');
        getline(ss, emp.department, ',');
        getline(ss, salaryStr, ','); emp.salary = stof(salaryStr);
        employees.push_back(emp);
    }
    return employees;
}

// Save employees to file
void saveEmployees(const vector<Employee>& employees) {
    ofstream file("employees.txt");
    for (const auto& emp : employees) {
        file << emp.id << "," << emp.name << "," << emp.department << "," << emp.salary << "\n";
    }
}

// Add new employee
void addEmployee() {
    Employee emp;
    cout << "Enter ID: "; cin >> emp.id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, emp.name);
    cout << "Enter Department: "; getline(cin, emp.department);
    cout << "Enter Salary: "; cin >> emp.salary;

    ofstream file("employees.txt", ios::app);
    file << emp.id << "," << emp.name << "," << emp.department << "," << emp.salary << "\n";

    ofstream log("log.txt", ios::app);
    log << "Added employee ID: " << emp.id << endl;

    cout << "Employee added successfully.\n";
}

// View all employees
void viewEmployees() {
    auto employees = loadEmployees();
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name
             << ", Dept: " << emp.department << ", Salary: " << emp.salary << endl;
    }
}

// Search employee by ID
void searchByID() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    auto employees = loadEmployees();
    bool found = false;
    for (const auto& emp : employees) {
        if (emp.id == id) {
            cout << "Found: " << emp.name << ", " << emp.department << ", Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Employee not found.\n";
}

// Update salary
void updateSalary() {
    int id;
    float newSalary;
    cout << "Enter ID to update salary: ";
    cin >> id;
    cout << "Enter new salary: ";
    cin >> newSalary;

    auto employees = loadEmployees();
    bool found = false;
    for (auto& emp : employees) {
        if (emp.id == id) {
            emp.salary = newSalary;
            found = true;
            break;
        }
    }

    if (found) {
        saveEmployees(employees);
        cout << "Salary updated.\n";
    } else {
        cout << "Employee not found.\n";
    }
}

// Total and average salary
void totalAndAverageSalary() {
    auto employees = loadEmployees();
    float total = 0;
    for (auto& emp : employees) total += emp.salary;
    float avg = employees.empty() ? 0 : total / employees.size();

    cout << "Total Salary: " << total << "\nAverage Salary: " << avg << endl;
}

int main() {
    int choice;
    do {
        cout << "\n--- Employee Management Menu ---\n";
        cout << "1. Add Employee\n2. View Employees\n3. Search by ID\n4. Update Salary\n5. Total & Average Salary\n0. Exit\nChoose: ";
        cin >> choice;

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchByID(); break;
            case 4: updateSalary(); break;
            case 5: totalAndAverageSalary(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}

