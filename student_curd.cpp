#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string department;
    float cgpa;

    void input() {
        cout << "Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Department: ";
        getline(cin, department);
        cout << "CGPA: ";
        cin >> cgpa;
    }

    void show() {
        cout << "Roll No: " << rollNo << "\nName: " << name
             << "\nDepartment: " << department << "\nCGPA: " << cgpa << "\n";
    }
};

void addStudent() {
    Student s;
    s.input();
    ofstream file("students.txt", ios::app);
    file << s.rollNo << " " << s.name << " " << s.department << " " << s.cgpa << "\n";
    file.close();
    cout << "Student added.\n";
}

void viewStudents() {
    Student s;
    ifstream file("students.txt");
    while (file >> s.rollNo >> s.name >> s.department >> s.cgpa) {
        s.show();
        cout << "----------------\n";
    }
    file.close();
}

void searchStudent() {
    Student s;
    int r, found = 0;
    cout << "Enter roll no to search: ";
    cin >> r;
    ifstream file("students.txt");
    while (file >> s.rollNo >> s.name >> s.department >> s.cgpa) {
        if (s.rollNo == r) {
            s.show();
            found = 1;
            break;
        }
    }
    if (!found) cout << "Student not found.\n";
    file.close();
}

void updateStudent() {
    Student s;
    int r, found = 0;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    cout << "Enter roll no to update: ";
    cin >> r;
    while (file >> s.rollNo >> s.name >> s.department >> s.cgpa) {
        if (s.rollNo == r) {
            cout << "Enter new data:\n";
            s.input();
            found = 1;
        }
        temp << s.rollNo << " " << s.name << " " << s.department << " " << s.cgpa << "\n";
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) cout << "Student updated.\n";
    else cout << "Student not found.\n";
}

void deleteStudent() {
    Student s;
    int r, found = 0;
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    cout << "Enter roll no to delete: ";
    cin >> r;
    while (file >> s.rollNo >> s.name >> s.department >> s.cgpa) {
        if (s.rollNo == r) {
            found = 1;
            continue;
        }
        temp << s.rollNo << " " << s.name << " " << s.department << " " << s.cgpa << "\n";
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) cout << "Student deleted.\n";
    else cout << "Student not found.\n";
}

int main() {
    int ch;
    do {
        cout << "\n1. Add\n2. View\n3. Search\n4. Update\n5. Delete\n6. Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 6);
    return 0;
}

