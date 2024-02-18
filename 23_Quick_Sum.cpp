#include <iostream>
#include <vector>

using namespace std;

void check(vector<vector<int>> v) {
    cout << "---------------------\n";
    for (auto &i : v) {
        for (auto &j : i) cout << j << " ";
        cout << "\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k, r1, c1, r2, c2;

    cin >> n >> m >> k;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    auto p = v;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            p[i][j] = v[i][j] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    while (k--) {
        cin >> r1 >> c1 >> r2 >> c2;
        r1++, c1++, r2++, c2++;
        cout << p[r2][c2] - p[r1 - 1][c2] - p[r2][c1 - 1] + p[r1 - 1][c1 - 1] << "\n";
    }
    return 0;
}

/*
3 5 7
1 2 3 4 5
6 6 6 6 6
7 7 3 1 1
0 0 0 0
0 0 1 1
1 1 2 1
1 1 2 3
1 0 2 2
0 1 2 2
0 0 2 4
*/