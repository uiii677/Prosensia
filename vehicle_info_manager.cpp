#include <iostream>
using namespace std;

class Vehicle {
private:
    string company;
    string model;
    int year;
    static int count;

public:
    Vehicle() {
        company = "Unknown";
        model = "Unknown";
        year = 0;
        count++;
        cout << "Default Constructor called.\n";
    }

    Vehicle(string c, string m, int y) {
        company = c;
        model = m;
        year = y;
        count++;
        cout << "Parameterized Constructor called.\n";
    }

    void display() {
        cout << "Company: " << company << ", Model: " << model << ", Year: " << year << endl;
    }

    ~Vehicle() {
        cout << "Destructor called for " << company << " " << model << endl;
        count--;
    }

    static void showCount() {
        cout << "Total Vehicles: " << count << endl;
    }
};

int Vehicle::count = 0;

int main() {
    Vehicle::showCount();

    Vehicle v1;
    Vehicle v2("Toyota", "Corolla", 2020);
    Vehicle v3("Honda", "Civic", 2022);

    v1.display();
    v2.display();
    v3.display();

    Vehicle::showCount();

    return 0;
}

