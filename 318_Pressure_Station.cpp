#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void check(vector<int> v) {
    for (auto &e : v) cout << e << " ";
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, K;
    cin >> n >> K;
    vector<int> v(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    dp[1] = v[1];
    // check(v);
    for (int i = 1; i <= n; i++) {
        dp[i] = 1e9 + 7;
        for (int j = i; j >= max(1, i - 2 * K - 1); j--) {
            dp[i] = min(dp[i], dp[j] + v[i]);
        }
    }
    check(dp);
    cout << dp[n] << "\n";
    return 0;
}

/*
5 1
1 99 1 99 1
= 3

5 1
99 1 99 1 99
= 2

7 3
1 2 3 4 3 2 1
= 2
*/