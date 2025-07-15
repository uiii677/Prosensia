#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;

public:
    // Constructor
    BankAccount(int accNo, string name, double initialBalance) {
        accountNumber = accNo;
        accountHolder = name;
        balance = initialBalance;
    }

    // Deposit method
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    // Display account information
    void displayInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    // Create BankAccount objects
    BankAccount acc1(101, "Ali", 1000.0);
    BankAccount acc2(102, "Sara", 1500.0);

    // Perform operations
    acc1.deposit(500);
    acc1.withdraw(300);
    acc1.displayInfo();

    acc2.deposit(1000);
    acc2.withdraw(2000); // Test insufficient balance
    acc2.displayInfo();

    return 0;
}

