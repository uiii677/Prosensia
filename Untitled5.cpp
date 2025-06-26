#include <iostream>
using namespace std;

int main() {
    string Name;
    int Age;
    float CGPA;

    cout << "Enter your Name, age and CGPA: " << endl;
    cin >> Name >> Age >> CGPA;

    if (Age >= 18 && CGPA >= 2.5) {
        cout << "Hello " << Name << ", you are eligible to apply!" << endl;
    } else {
        cout << "Sorry " << Name << ", you are not eligible to apply." << endl;
        if (Age < 18) {
            cout << "Reason: You must be at least 18 years old." << endl;
        }
        if (CGPA < 2.5) {
            cout << "Reason: Your CGPA must be at least 2.5." << endl;
        }
    }

    return 0;
}

