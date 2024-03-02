#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dp;
vector<int> price, weight, ans;
int n, m;

void recur(int i, int j) {
    if (i == 0 || j == 0) return;
    if (dp[i][j] == dp[i - 1][j]) {
        recur(i - 1, j);
    } else {
        ans.push_back(i);
        recur(i - 1, j - weight[i]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;

    dp.resize(n + 1, vector<int>(m + 1));
    price.resize(n + 1);
    weight.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> price[i];
    for (int i = 1; i <= n; i++) cin >> weight[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) cin >> dp[i][j];

    recur(n, m);
    cout << ans.size() << "\n";
    for (auto& e : ans) cout << e << " ";
    cout << "\n";
    return 0;
}

/*
5 3
6 9 5 4 3
2 3 1 1 2
0 0 0 0
0 0 6 6
0 0 6 9
0 5 6 11
0 5 9 11
0 5 9 11
= 2 1,3

5 5
3 10 6 3 5
5 5 3 1 1
0 0 0 0 0 0
0 0 0 0 0 3
0 0 0 0 0 10
0 0 0 6 6 10
0 3 3 6 9 10
0 5 8 8 11 14
= 3 5,4,3
*/