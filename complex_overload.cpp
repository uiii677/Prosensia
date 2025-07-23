#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    bool operator>(const Complex& c) const {
        return magnitude() > c.magnitude();
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }
};

int main() {
    Complex a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "a + b: " << a + b << endl;
    cout << "a - b: " << a - b << endl;
    cout << "a * b: " << a * b << endl;
    cout << (a == b ? "a == b" : "a != b") << endl;
    cout << (c > d ? "c > d" : (d > c ? "d > c" : "c == d")) << endl;

    return 0;
}

