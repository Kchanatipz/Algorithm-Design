#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int mod = 32717;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k, x, y;
    cin >> n >> k;
    vector<vector<int>> p(n);
    vector<int> a(k), dp(n);
    for (int i = 0; i < k; i++)
        cin >> a[i];
    for (int i = k; i < n; i++) {
        cin >> x;
        while (x--) {
            cin >> y;
            p[i].push_back(y);
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < k) {
            dp[i] = a[i];
        } else {
            for (int j : p[i]) {
                if (i - j < 0)
                    continue;
                dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}

/*
10 2
1 1
2 1 2
2 1 2
2 1 2
2 1 2
2 1 2
2 1 2
2 1 2
2 1 2
= 1 1 2 3 5 8 13 21 34 55

7 3
1 2 3
3 1 1 1
2 2 1
1 4
1 8
= 1 2 3 9 12 2 0
*/