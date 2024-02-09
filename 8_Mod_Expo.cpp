#include <iostream>

using namespace std;

int recur(int x, int n, int k) {
    // cout << x << " " << n << " " << k << "\n";
    if (pow(x, n) < k) return pow(x, n);
    int tmp = recur(x, n / 2, k);
    // cout << tmp << "\n";
    if (n % 2 == 0) {
        return (tmp * tmp) % k;
    }
    tmp = (tmp * tmp) % k;
    return (tmp * (x % k)) % k;
}

int main() {
    int x, n, k;
    cin >> x >> k >> n;
    cout << recur(x, k, n) << "\n";
    return 0;
}