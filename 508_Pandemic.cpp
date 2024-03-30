#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int r, c, t;
vector<vector<int>> graph;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void spread(int ux, int uy, int x, int y) {
    int vx = ux + x;
    int vy = uy + y;
    if (vx < 0 || vy < 0 || vx >= r || vy >= c)
        return;
    if (graph[vx][vy] == 0 && dist[vx][vy] == -1 && dist[ux][uy] <= t - 1) {
        graph[vx][vy] = 1;
        q.push({vx, vy});
        dist[vx][vy] = dist[ux][uy] + 1;
    }
    return;
}

void bfs() {
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        spread(ux, uy, -1, 0);
        spread(ux, uy, 1, 0);
        spread(ux, uy, 0, -1);
        spread(ux, uy, 0, 1);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> r >> c >> t;
    graph.resize(r, vector<int>(c));
    dist.resize(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    bfs();

    int count = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (graph[i][j] == 1)
                count++;
    cout << count << "\n";
    return 0;
}

/*
5 4 3
0 0 0 0
0 0 0 0
0 0 0 0
0 2 1 0
0 0 0 0
= 14

3 3 2
0 0 1
0 0 0
0 0 1
= 8

1 12 3
0 1 0 0 0 0 0 0 0 1 0 0
= 11
*/