#include <iostream>
#include <queue>
#include <vector>
#define tuple tuple<int, int, int>  // cost,row,col

using namespace std;
const int MAX = 1e9 + 7;
int dirX[6] = {0, 0, -1, 1};
int dirY[6] = {-1, 1, 0, 0};
int r, c, startX, startY, stopX, stopY;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> r >> c >> startX >> startY >> stopX >> stopY;
    vector<vector<int>> cost(r + 1, vector<int>(c + 1));
    vector<vector<int>> dis(r + 1, vector<int>(c + 1, MAX));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> cost[i][j];

    priority_queue<tuple, vector<tuple>, greater<tuple>> pq;
    pq.emplace(cost[startX][startY], startX, startY);
    dis[startX][startY] = cost[startX][startY];
    while (!pq.empty()) {
        auto [k, x, y] = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int dx = x + dirX[i];
            int dy = y + dirY[i];

            if (dx <= 0 || dy <= 0 || dx > r || dy > c)
                continue;

            if (dis[x][y] + cost[dx][dy] < dis[dx][dy]) {
                dis[dx][dy] = dis[x][y] + cost[dx][dy];
                pq.emplace(dis[dx][dy], dx, dy);
            }
        }
    }
    cout << cost[stopX][stopY] << "\n";
    return 0;
}