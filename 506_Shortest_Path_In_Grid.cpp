#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int r, c;
string str;
vector<vector<char>> grid;
vector<vector<int>> dist;
queue<pair<int, int>> q;

void move(int ux, int uy, int x, int y) {
    int vx = ux + x;
    int vy = uy + y;
    if (vx < 0 || vy < 0 || vx >= r || vy >= c)
        return;
    if (dist[vx][vy] == -1 && grid[vx][vy] == '.') {
        dist[vx][vy] = dist[ux][uy] + 1;
        q.push({vx, vy});
    }
}

void bfs() {
    q.push({0, 0});
    dist[0][0] = 0;
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        move(ux, uy, -1, 0);
        move(ux, uy, 1, 0);
        move(ux, uy, 0, -1);
        move(ux, uy, 0, 1);
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> r >> c;
    grid.resize(r, vector<char>(c));
    dist.resize(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            grid[i][j] = str[j];
        }
    }

    bfs();
    cout << dist[r - 1][c - 1] << "\n";
    return 0;
}
/*
5 5
.#...
.#...
.#...
.#.#.
...#.
= 12

5 5
.....
...##
...#.
..##.
.###.
= -1
*/