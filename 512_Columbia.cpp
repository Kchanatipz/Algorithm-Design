#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1e9 + 7;
int r, c;
vector<vector<int>> graph;
vector<vector<int>> fee;
queue<pair<int, int>> q;

void travel(int ux, int uy, int x, int y) {
    int vx = ux + x;
    int vy = uy + y;
    // cout << vx << " " << vy << "\n";
    if (vx < 0 || vy < 0 || vx >= r || vy >= c)
        return;
    fee[vx][vy] = min(fee[vx][vy], fee[ux][uy] + graph[vx][vy]);
    q.push({vx, vy});
}

void dfs() {
    q.push({0, 0});
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        cout << ux << " " << uy << "\n";
        travel(ux, uy, -1, 0);
        travel(ux, uy, 1, 0);
        travel(ux, uy, 0, -1);
        travel(ux, uy, 0, 1);
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> r >> c;
    graph.resize(r, vector<int>(c));
    fee.resize(r, vector<int>(c, INF));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }

    fee[0][0] = 0;
    dfs();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << fee[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
4 4
1 1 1 1
9 8 7 1
1 1 1 1
1 2 4 9

0 1 2 3
9 9 9 4
8 7 6 5
9 9 10 14
*/