#include <iostream>
using namespace std;

// Extended Euclidean Algorithm: finds x, y such that ax + by = gcd(a, b)
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Solves a·x = b (mod m)
void solveLinearCongruence(int a, int b, int m) {
    int x, y;
    int d = extendedGCD(a, m, x, y); // d = gcd(a, m)

    // No solution if d does not divide b
    if (b % d != 0) {
        cout << "No solution exists for the given linear congruence.\n";
        return;
    }

    // Basic solution
    int x0 = (x * (b / d)) % m;
    if (x0 < 0) x0 += m; // Make it positive

    cout << "Solutions to " << a << "·x = " << b << " mod " << m << ":\n";
    for (int i = 0; i < d; ++i) {
        int solution = (x0 + i * (m / d)) % m;
        cout << "x = " << solution << " mod " << m << endl;
    }
}

int main() {
    int a, b, m;
    cout << "Enter values for a, b, and m in the equation a·x = b mod m:\n";
    cin >> a >> b >> m;

    solveLinearCongruence(a, b, m);
    return 0;
}
