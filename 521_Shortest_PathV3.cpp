#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
// dir -> {odd,even}
int dirX[2][6] = {{-1, 1, 0, 0, -1, -1}, {-1, 1, 0, 0, 1, 1}};
int dirY[2][6] = {{0, 0, -1, 1, -1, 1}, {0, 0, -1, 1, -1, 1}};
const int MAX = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C, a1, b1, a2, b2;
    cin >> R >> C >> b1 >> a1 >> b2 >> a2;
    vector<vector<int>> hex(R, vector<int>(C)), dis(R, vector<int>(C, MAX));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> hex[i][j];

    priority_queue<tuple<int, int, int>> pq;
    dis[a1 - 1][b1 - 1] = hex[a1 - 1][b1 - 1];
    pq.emplace(-hex[a1 - 1][b1 - 1], a1 - 1, b1 - 1);
    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();
        for (int i = 0; i < 6; i++) {
            int dx = x + dirX[y % 2][i];
            int dy = y + dirY[y % 2][i];
            if (dx < 0 || dy < 0 || dx >= R || dy >= C) continue;
            if (dis[x][y] + hex[dx][dy] < dis[dx][dy]) {
                dis[dx][dy] = dis[x][y] + hex[dx][dy];
                pq.emplace(-dis[dx][dy], dx, dy);
            }
        }
    }
    cout << dis[a2 - 1][b2 - 1] << "\n";
    return 0;
}

/*
2 2 1 1 2 2
4 5
6 7
= 16

4 6 1 3 6 2
3 4 222 666 1 1
2 285 88 999 777 6
7 545 99 3 18 48
8 6 200 144 260 69
= 227
*/