#include <iostream>
#include <vector>

using namespace std;
int n, ans = -(1e9 + 7);
vector<vector<int>> cost(25, vector<int>(25));
vector<bool> visited;

void recur(int from, int acc, int step, int cnt) {
    for (int i = 0; i < cnt; i++) cout << " -";
    cout << from << " " << acc << " " << step << "\n";
    bool check = true;
    for (int i = 0; i < n - 1; i++) {
        if (!visited[i]) {
            check = false;
            break;
        }
    }
    if (check && step == n - 1) {
        cout << acc + cost[from][n - 1] << "\n";
        ans = max(ans, acc + cost[from][n - 1]);
        return;
    }
    for (int to = 1; to < n - 1; to++) {
        if (visited[to]) continue;
        visited[to] = true;
        recur(to, acc + cost[from][to], step + 1, cnt + 1);
        visited[to] = false;
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    visited.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    visited[0] = true;
    recur(0, 0, 1, 0);
    cout << "ANS : " << ans << "\n";
    return 0;
}

/*
4
0 1 -1 2
2 0 5 -3
1 15 0 3
3 -1 5 0
= 11

4
0 1 -1 2
2 0 1 -3
1 15 0 13
3 -1 5 0
= 15
*/