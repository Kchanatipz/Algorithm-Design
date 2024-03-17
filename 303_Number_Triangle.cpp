#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, ans = -(1e9 + 7);
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/