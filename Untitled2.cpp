#include <iostream>
using namespace std;

bool isOdd(int n) {
    return n % 2 != 0;
}

void conditionalSwap(int* x, int* y) {
    int diff = (*x > *y) ? (*x - *y) : (*y - *x);
    if (diff > 10) {
        int* temp = new int(*x);
        *x = *y;
        *y = *temp;
        delete temp;
    }
}

void printArrayViaPointer(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " @ " << (arr + i) << endl;
    }
}

int* findFirstEven(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) % 2 == 0)
            return (arr + i);
    }
    return nullptr;
}

void incrementOddsByAddress(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (isOdd(*(arr + i))) {
            *(arr + i) += 1;
        }
    }
}

int main() {
    int a, b;
    int arr[5];

    cin >> a >> b;
    for (int i = 0; i < 5; ++i)
        cin >> arr[i];

    cout << "Before Swap: a = " << a << ", b = " << b << endl;
    conditionalSwap(&a, &b);
    cout << "After Swap : a = " << a << ", b = " << b << endl;

    printArrayViaPointer(arr, 5);

    int* evenPtr = findFirstEven(arr, 5);
    if (evenPtr != nullptr)
        cout << "First even found: " << *evenPtr << endl;
    else
        cout << "No even number found in array." << endl;

    incrementOddsByAddress(arr, 5);
    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

