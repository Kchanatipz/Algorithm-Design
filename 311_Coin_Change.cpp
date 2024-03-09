#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int LARGE = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n), dp(k + 1, LARGE);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coin[j]) {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    cout << dp[k] << "\n";
    return 0;
}

/*
4 28
10 5 2 1
= 5

3 13
5 4 1
= 3
*/