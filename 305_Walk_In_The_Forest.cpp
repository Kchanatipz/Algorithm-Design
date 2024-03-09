#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1, -999999));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> k;
            if (i == 1 && j == 1) {
                v[i][j] = k;
            } else {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]) + k;
                v[i][j] = max(v[i][j], v[i - 1][j - 1] + 2 * k);
            }
        }
    }
    cout << v[n][m] << "\n";
    return 0;
}

/*
1 5
1 2 3 4 5
15

3 3
1 1 10
1 7 10
1 10 20
55

3 3
1 1 10
1 7 10
1 9 7
32
*/