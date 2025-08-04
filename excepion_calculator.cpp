#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

void logException(const char* message) {
    ofstream log("error_log.txt", ios::app);
    if (log.is_open()) {
        log << message << endl;
        log.close();
    } else {
        cerr << "Cannot open log file." << endl;
    }
}

double performOperation(double a, double b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') {
        if (b == 0) throw "Division by zero!";
        return a / b;
    } else {
        throw "Invalid operator!";
    }
}

int main() {
    double num1, num2;
    char op;

    try {
        cout << "Enter first number: ";
        if (!(cin >> num1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw "Invalid input for first number!";
        }

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        if (!(cin >> num2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw "Invalid input for second number!";
        }

        double result = performOperation(num1, num2, op);
        cout << "Result: " << result << endl;
    }
    catch (const char* errorMsg) {
        cerr << "Exception: " << errorMsg << endl;
        logException(errorMsg);
    }

}
