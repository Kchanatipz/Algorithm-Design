#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int mod = 1997;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j == 1 || i == j)
                v[i][j] = 1;
            else
                v[i][j] = ((v[i - 1][j] * i) % mod + v[i - 1][j - 1]) % mod;
        }
    }
    cout << v[n][k] << "\n";
    return 0;
}

/*
3 2 = 3
4 1 = 1
4 2 = 7
4 3 = 6
7 3 = 301
499 23 = 1432
*/