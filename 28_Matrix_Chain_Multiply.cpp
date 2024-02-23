#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void update(vector<vector<int>> v) {
    cout << "--------------------\n";
    for (auto &i : v) {
        for (auto &j : i) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, x;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        dp[i][i + 1] = v[i - 1] * v[i] * v[i + 1];
    }
    for (int k = 2; k < n - 1; k++) {
        for (int i = 1; i < n; i++) {
            x = 1e9 + 7;
        }
    }
    /*
        for (r = 2; r <= n; r++)
            for (i = 1; i <= n; i++) {
                min = 1000000000;
                for (j = i; j < i + r; j++) {
                    v = m[i][j] + m[j + 1][i + r] + a[i - 1] * a[i + r] * a[j];
                    if (v < min) min = v;
                }
                m[i][i + r] = min;
            }

    */
    update(dp);
    cout << dp[1][n - 1] << "\n";
    return 0;
}

/*
6
10 5 1 5 10 2
140

3
10 10 10 1
200

7
92 32 7 3 29 74 57 93
70167
*/