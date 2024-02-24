#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, close, far;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> k;
        v[i] = max(v[i - 1], v[max(0, i - 3)] + k);
    }
    cout << v[n] << "\n";
    return 0;
}

/*
5
1 1 1 1 1
= 2

3
3 4 2
= 4

10
48 1 3 95 2 1 3 44 22 2
= 187
*/