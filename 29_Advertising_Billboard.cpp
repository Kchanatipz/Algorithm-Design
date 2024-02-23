#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i > 1) {
            v[i] = max(v[i - 1], v[i - 2] + v[i]);
        }
    }
    cout << v[n] << "\n";
    return 0;
}

/*
3
3 4 2
= 5

10
48 1 3 95 2 1 3 44 22 2
= 190
*/