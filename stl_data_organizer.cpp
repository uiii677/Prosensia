#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm> // for sort
using namespace std;

// Function to display marks
void displayMarks(const vector<int>& marks) {
    cout << "Student Marks: ";
    for (int mark : marks)
        cout << mark << " ";
    cout << endl;
}

// Function to display departments
void displayDepartments(const set<string>& departments) {
    cout << "Departments: ";
    for (const string& dept : departments)
        cout << dept << " ";
    cout << endl;
}

// Function to display department-wise student count
void displayDepartmentCounts(const map<string, int>& deptCount) {
    cout << "Department Student Count:\n";
    for (const auto& entry : deptCount)
        cout << entry.first << " -> " << entry.second << endl;
}

int main() {
    vector<int> marks;
    set<string> departments;
    map<string, int> deptCount;

    int choice;
    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Add Student Mark\n";
        cout << "2. Sort and View Marks\n";
        cout << "3. Add Department\n";
        cout << "4. Add Student to Department\n";
        cout << "5. View Departments\n";
        cout << "6. View Department Student Counts\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int mark;
            cout << "Enter mark: ";
            cin >> mark;
            marks.push_back(mark);
        }
        else if (choice == 2) {
            sort(marks.begin(), marks.end());
            displayMarks(marks);
        }
        else if (choice == 3) {
            string dept;
            cout << "Enter department name: ";
            cin >> dept;
            departments.insert(dept);
        }
        else if (choice == 4) {
            string dept;
            cout << "Enter department name: ";
            cin >> dept;
            departments.insert(dept);
            deptCount[dept]++;
        }
        else if (choice == 5) {
            displayDepartments(departments);
        }
        else if (choice == 6) {
            displayDepartmentCounts(deptCount);
        }

    } while (choice != 0);

    return 0;
}

