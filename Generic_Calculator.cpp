#include <iostream>
#include <cassert>
using namespace std;

// Template Functions
template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
T subtract(T a, T b) {
    return a - b;
}

template <typename T>
T multiply(T a, T b) {
    return a * b;
}

// Template specialization for division to handle divide by 0
template <typename T>
T divide(T a, T b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return a / b;
}

// Class Template
template <typename T>
class Calculator {
public:
    T a, b;
    Calculator(T x, T y) : a(x), b(y) {}

    void performAll() {
        cout << "Addition: " << add(a, b) << endl;
        cout << "Subtraction: " << subtract(a, b) << endl;
        cout << "Multiplication: " << multiply(a, b) << endl;
        cout << "Division: " << divide(a, b) << endl;
    }
};

// Menu-driven interface
void showMenu() {
    cout << "\n====== Generic Calculator ======" << endl;
    cout << "Select data type:" << endl;
    cout << "1. int\n2. float\n3. double\n4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 4) break;

        cout << "Enter two values: ";
        switch (choice) {
            case 1: {
                int a, b;
                cin >> a >> b;
                Calculator<int> calc(a, b);
                calc.performAll();
                break;
            }
            case 2: {
                float a, b;
                cin >> a >> b;
                Calculator<float> calc(a, b);
                calc.performAll();
                break;
            }
            case 3: {
                double a, b;
                cin >> a >> b;
                Calculator<double> calc(a, b);
                calc.performAll();
                break;
            }
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }

    // Unit Tests
    assert(add(5, 3) == 8);
    assert(subtract(10.5, 4.5) == 6.0);
    assert(multiply(2, 3) == 6);
    assert(divide(10, 2) == 5);
    assert(divide(10, 0) == 0); // division by zero case

    cout << "\nAll tests passed successfully!" << endl;

    return 0;
}

