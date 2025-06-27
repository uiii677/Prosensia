#include <iostream>
using namespace std;

int main() {
    int number, reversed = 0;

    cout << "Enter an integer to reverse: ";
    cin >> number;

    int original = number;

    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
        number = -number;  // Make positive for reversal
    }

    while (number != 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number = number / 10;
    }

    if (isNegative)
        reversed = -reversed;

    cout << "Reversed: " << reversed << endl;

    return 0;
}

