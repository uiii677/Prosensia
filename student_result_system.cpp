#include <iostream>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];
    float total;
    float average;

public:
    // Parameterized Constructor
    Student(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateResult();
    }

    // Calculate Total and Average
    void calculateResult() {
        total = marks[0] + marks[1] + marks[2];
        average = total / 3;
    }

    // Calculate Grade based on average
    char calculateGrade() const {
        if (average >= 85) return 'A';
        else if (average >= 70) return 'B';
        else if (average >= 60) return 'C';
        else if (average >= 50) return 'D';
        else return 'F';
    }

    // Display Student Details
    void display() const {
        cout << "Roll No: " << rollNo << "\nName: " << name;
        cout << "\nMarks: " << marks[0] << ", " << marks[1] << ", " << marks[2];
        cout << "\nTotal: " << total << "\nAverage: " << fixed << setprecision(2) << average;
        cout << "\nGrade: " << calculateGrade() << "\n" << endl;
    }

    // Getter for total marks
    float getTotal() const {
        return total;
    }
};

// Sort function (Bubble Sort)
void sortStudents(Student s[], int n) {
    for(int i = 0; i < n-1; ++i) {
        for(int j = 0; j < n-i-1; ++j) {
            if(s[j].getTotal() < s[j+1].getTotal()) {
                swap(s[j], s[j+1]);
            }
        }
    }
}

int main() {
    const int size = 3;
    Student students[size] = {
        Student(1, "Ali", 78, 82, 89),
        Student(2, "Sara", 90, 88, 85),
        Student(3, "Zain", 65, 70, 72)
    };

    sortStudents(students, size);

    cout << "---- Sorted Student Results (by Total Marks) ----\n\n";
    for(int i = 0; i < size; ++i) {
        students[i].display();
    }

    return 0;
}

