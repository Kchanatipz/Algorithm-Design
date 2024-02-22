#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, ans = -1;
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    cin >> v[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i + 1; j++) {
            cin >> v[i][j];
            v[i][j] = max(v[i - 1][j - 1], v[i - 1][j]) + v[i][j];
            ans = max(ans, v[i][j]);
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