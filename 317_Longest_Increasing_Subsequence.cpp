#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}

/*
5
3 1 4 5 2
= 3

13
7 0 10 21 1 6 22 4 3 5 9 8 71
= 6
*/