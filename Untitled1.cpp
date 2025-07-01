#include <iostream>
#include <iomanip>
using namespace std;

// Function to calculate sum
int getSum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

// Function to find index of first maximum
int getMaxIndex(int arr[], int size) {
    int maxIndex = 0;
    for(int i = 1; i < size; i++)
        if(arr[i] > arr[maxIndex])
            maxIndex = i;
    return maxIndex;
}

// Function to find index of first minimum
int getMinIndex(int arr[], int size) {
    int minIndex = 0;
    for(int i = 1; i < size; i++)
        if(arr[i] < arr[minIndex])
            minIndex = i;
    return minIndex;
}

// Function to calculate average (rounded to 2 decimal places)
float getAverage(int arr[], int size) {
    int sum = getSum(arr, size);
    return static_cast<float>(sum) / size;
}

// Function to reorder array: even first, odd later (preserve order)
void reorderEvenOdd(int original[], int reordered[], int size) {
    int index = 0;

    // First add even numbers
    for(int i = 0; i < size; i++)
        if(original[i] % 2 == 0)
            reordered[index++] = original[i];

    // Then add odd numbers
    for(int i = 0; i < size; i++)
        if(original[i] % 2 != 0)
            reordered[index++] = original[i];
}

int main() {
    const int SIZE = 5;
    int arr[SIZE];
    int reordered[SIZE];

    // Input
    cout << "Enter 5 numbers: ";
    for(int i = 0; i < SIZE; i++)
        cin >> arr[i];

    // Processing
    int sum = getSum(arr, SIZE);
    float avg = getAverage(arr, SIZE);
    int maxIdx = getMaxIndex(arr, SIZE);
    int minIdx = getMinIndex(arr, SIZE);
    reorderEvenOdd(arr, reordered, SIZE);

    // Output
    cout << "\n=== Analyzing Array ===\n";
    cout << "Sum = " << sum << endl;
    cout << fixed << setprecision(2);
    cout << "Average = " << avg << endl;
    cout << "Maximum = " << arr[maxIdx] << " at position " << maxIdx + 1 << endl;
    cout << "Minimum = " << arr[minIdx] << " at position " << minIdx + 1 << endl;

    cout << "\nReordered Array: ";
    for(int i = 0; i < SIZE; i++)
        cout << reordered[i] << " ";

    cout << endl;
    return 0;
}

