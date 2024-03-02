#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void check(vector<vector<int>> v) {
    cout << ">-<\n";
    for (auto &i : v) {
        for (auto &j : i) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> coin(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
    check(dp);
    cout << dp[n][k] << "\n";
    return 0;
}

/*
4 28
5 10 5 2 1
= 5

3 13
5 4 1
= 3
*/