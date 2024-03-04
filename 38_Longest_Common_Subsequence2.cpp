#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, m;
string a, b, ans = "";
vector<vector<int>> v;

void recur(int r, int c) {
    if (r == 0 || c == 0) return;
    if (a[r - 1] == b[c - 1]) {
        ans = a[r - 1] + ans;
        recur(r - 1, c - 1);
    } else if (v[r - 1][c] > v[r][c - 1])
        recur(r - 1, c);
    else
        recur(r, c - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> a >> b;
    v.resize(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    recur(n, m);
    cout << ans << "\n";
    return 0;
}

/*
4 5
hero
hello
0 0 0 0 0 0
0 1 1 1 1 1
0 1 2 2 2 2
0 1 2 2 2 2
0 1 2 2 2 3
= heo
*/