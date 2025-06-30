#include <iostream>
using namespace std;

// Part 1 – Recursive Factorial
int factorial(int n) {
    if (n > 12) {
        cout << "Warning: Value too large, result may overflow!" << endl;
        return -1;
    }
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

// Part 2 – Conditional Max with Tie Logic
int customMax(int a, int b, int c) {
    if (a == b && b == c) {
        return 0; 
    }
    if (a == b && a > c) return a + b;
    if (a == c && a > b) return a + c;
    if (b == c && b > a) return b + c;

    
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

// Part 3 – Banner Function
void printBanner(string message) {
    cout << "\n=== " << message << " ===" << endl;
}


int main() {
    int num, a, b, c;


    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter 3 numbers: ";
    cin >> a >> b >> c;

    
    printBanner("Student Logic Execution");

    int factResult = factorial(num);
    if (factResult != -1)
        cout << "Factorial of " << num << " is: " << factResult << endl;

    int maxResult = customMax(a, b, c);
    cout << "Max function result is: " << maxResult << endl;

    return 0;
}

