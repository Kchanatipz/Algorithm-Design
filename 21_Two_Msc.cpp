#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, max_current, max_global, left, right, c2, g2;
    cin >> n;
    vector<int> v(n), u;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    max_current = max_global = v[0];
    left = right = 1;
    for (int i = 1; i < n; i++) {
        cout << left << " " << right << "\n";
        if (v[i] > max_current + v[i]) {
            left = i;
            max_current = v[i];
        } else {
            max_current += v[i];
        }
        // max_current = max(v[i], max_current + v[i]);
        if (max_current > max_global) {
            max_global = max_current;
            right = i;
        }
    }
    cout << max_global << " " << left << " " << right << "\n";
    // c2 = g2 = v[0];
    // if (right == 0) right = left;
    // for (int i = 1; i < n; i++) {
    //     if (!(left <= i && i <= right)) {
    //         c2 = max(c2, c2 + v[i]);
    //         g2 = max(g2, c2);
    //     }
    // }
    // cout << max_global << " " << g2 << "\n";
    return 0;
}

/*
5
1 1 -10 1 1
4

5
1 2 3 4 5
15

4
-4 -2 -3 -1
-1

6
-1 -1 10 -1 -1 -2
10

10
-1 3 -1 2 -4 -5 7 -3 8 -4
16
*/