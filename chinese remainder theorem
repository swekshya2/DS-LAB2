#include <iostream>
#include <vector>
using namespace std;

// Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m, x = 1, y = 0;
    while (a > 1) {
        int q = a / m, t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    return (x + m0) % m0;
}

int chineseRemainder(const vector<int> &a, const vector<int> &m) {
    int prod = 1, sum = 0;
    for (int i =0;i<m.size(); ++i)
    prod *= m[i];
    for (int i = 0; i < a.size(); ++i) {
        int Mi = prod / m[i];
        int inv = modInverse(Mi, m[i]);
        sum += a[i] * Mi * inv;
    }
    return sum % prod;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), m(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> m[i];

    cout << "x = " << chineseRemainder(a, m) << endl;
    return 0;
}
