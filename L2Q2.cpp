#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Helper: Add two binary strings
string binaryAdd(string a, string b) {
    string result = "";
    int carry = 0;
    int len = max(a.length(), b.length());

    // Padding with 0s
    while (a.length() < len) a = '0' + a;
    while (b.length() < len) b = '0' + b;

    for (int i = len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry) result += '1';
    reverse(result.begin(), result.end());
    return result;
}

// Helper: Multiply two binary strings
string binaryMultiply(string a, string b) {
    string result = "0";
    int shift = 0;

    for (int i = b.length() - 1; i >= 0; i--) {
        if (b[i] == '1') {
            string temp = a;
            temp += string(shift, '0');  // shifting by appending 0s
            result = binaryAdd(result, temp);
        }
        shift++;
    }
    return result;
}

int main() {
    string bin1, bin2;
    cout << "Enter two binary numbers: ";
    cin >> bin1 >> bin2;

    string sum = binaryAdd(bin1, bin2);
    string product = binaryMultiply(bin1, bin2);

    cout << "Binary Addition Result: " << sum << endl;
    cout << "Binary Multiplication Result: " << product << endl;

    return 0;
}
