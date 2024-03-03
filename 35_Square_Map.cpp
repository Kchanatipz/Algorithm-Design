#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int r, c, ans = 0;
    char x;
    cin >> r >> c;

    vector<vector<int>> v(r + 1, vector<int>(c + 1));
    auto dp = v;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> x;
            if (x == '1') {
                int k = min({v[i - 1][j], v[i][j - 1], v[i - 1][j - 1]});
                if (v[i - 1][j] >= k && v[i][j - 1] >= k && v[i - 1][j - 1] >= k) {
                    v[i][j] = k + 1;
                }
            }
            ans = max(ans, v[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
1 10
1 1 1 1 1 1 1 0 1 1
= 1

5 5
0 0 0 1 0
0 1 1 1 1
0 0 1 1 1
0 0 1 1 1
0 0 1 1 1
= 3
*/