#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1)));
    dp[1][1][0] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                if (j >= 1) {
                    dp[i][j][k] += dp[i - 1][j - 1][k];
                }
                if (k >= 1) {
                    dp[i][1][k] += dp[i - 1][j][k - 1];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= M; i++) {
        ans += dp[N][i][K];
    }
    cout << ans << "\n";
    return 0;
}

/*
0 -> black
1 -> white

4 3 1
= 3

5 2 2
= 3

7 9 4
= 15
*/