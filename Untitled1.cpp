#include <iostream>
using namespace std;

// Function to check for spaces
bool hasSpace(string str) {
    for (char ch : str) {
        if (ch == ' ')
            return true;
    }
    return false;
}

// Function to convert to lowercase manually
void toLowerCase(string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

// Function to reverse string manually
string reverseString(const string& str) {
    string rev = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        rev += str[i];
    }
    return rev;
}

// Function to check palindrome using index-based comparison
bool isPalindrome(const string& str) {
    int start = 0, end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Function to count vowels, skipping consecutive duplicates
int countVowels(const string& str) {
    int count = 0;
    char lastVowel = '\0';
    for (char ch : str) {
        if ((ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') && ch != lastVowel) {
            count++;
            lastVowel = ch;
        } else if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
            lastVowel = '\0'; // reset if non-vowel appears
        }
    }
    return count;
}

int main() {
    string input;
    cout << "Enter a string (no spaces): ";
    cin >> input;

    if (hasSpace(input)) {
        cout << "?? Warning: Input should not contain spaces!" << endl;
        return 0;
    }

    toLowerCase(input);

    string reversed = reverseString(input);
    bool palindrome = isPalindrome(input);
    int vowelCount = countVowels(input);

    // Output Report
    cout << "\n=== String Analysis Report ===" << endl;
    cout << "Original:  " << input << endl;
    cout << "Reversed:  " << reversed << endl;
    cout << "Length:    " << input.length() << endl;
    cout << "Vowels:    " << vowelCount << endl;
    cout << "Palindrome: " << (palindrome ? "YES" : "NO") << endl;

    return 0;
}

