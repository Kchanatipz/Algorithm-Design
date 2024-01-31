#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

int pascal(int r, int c) {
    if (r == c) return 1;
    if (r == 1 || c == 1) return 1;
    return pascal(r - 1, c - 1) + pascal(r - 1, c);
}

int factorial1(int n) {
    if (n == 0) return 1;
    return n * factorial1(n - 1);
}

int factorial2(int n) {
    vector<int> v(n);
    v[0] = 1;
    for (int i = 1; i < n; i++) {
        v[i] = v[i - 1] * (i + 1);
    }
    return v[n - 1];
}

int factorial3(int n, int store) {
    if (n == 0) return store;
    return factorial3(n - 1, n * store);
}

int main() {
    int a;
    cin >> a;
    auto start1 = chrono::high_resolution_clock::now();
    cout << factorial1(a);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration1 = end1 - start1;
    cout << " " << duration1.count() << endl;

    auto start2 = chrono::high_resolution_clock::now();
    cout << factorial2(a);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end2 - start2;
    cout << " " << duration2.count() << endl;

    auto start3 = chrono::high_resolution_clock::now();
    cout << factorial3(a, 1);
    auto end3 = chrono::high_resolution_clock::now();
    chrono::duration<double> duration3 = end3 - start3;
    cout << " " << duration3.count() << endl;
}