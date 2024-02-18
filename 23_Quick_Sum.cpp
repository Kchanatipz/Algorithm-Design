#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v, store;
vector<int> u;
int n, m, k, x;

void check() {
    cout << "---------------------\n";
    for (auto &i : v) {
        for (auto &j : i) cout << j << " ";
        cout << "\n";
    }
    cout << "---------------------\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    v.resize(n);
    u.resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> u[j];
        v[i] = u;
    }
    check();
    while (k--) {
        cin >> x;
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