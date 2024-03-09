#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int mod = 1e6 + 3;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> v(k + 1), dp(n + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> v[i];
        dp[v[i]]++;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i - v[j] > 0) dp[i] = (dp[i] + dp[i - v[j]]) % mod;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}

/*
4 2
1 3
= 3

10 2
1 2
= 89

10 5
1 2 4 6 8
= 196

999 5
1 2 4 50 999
= 450169
*/
