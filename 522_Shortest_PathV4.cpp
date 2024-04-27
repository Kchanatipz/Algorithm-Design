#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define tuple tuple<int, int, int>  // cost,row,col

using namespace std;
const int MAX = 1e9 + 7;
// dir_ => {even, odd}
int dirX[2][6] = {{-1, -1, 1, 1, 0, 0}, {-1, -1, 1, 1, 0, 0}};
int dirY[2][6] = {{-1, 0, -1, 0, -1, 1}, {0, 1, 0, 1, -1, 1}};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int r, c, a1, b1, a2, b2;
    cin >> r >> c >> a1 >> b1 >> a2 >> b2;
    vector<vector<int>> cost(r + 1, vector<int>(c + 1));
    vector<vector<int>> dis(r + 1, vector<int>(c + 1, MAX));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> cost[i][j];

    priority_queue<tuple, vector<tuple>, greater<tuple>> pq;
    pq.emplace(cost[a1][b1], a1, b1);
    dis[a1][b1] = cost[a1][b1];
    while (!pq.empty()) {
        auto [k, x, y] = pq.top();
        pq.pop();

        for (int i = 0; i < 6; i++) {
            int dx = x + dirX[x % 2][i];
            int dy = y + dirY[x % 2][i];

            if (dx <= 0 || dy <= 0 || dx > r || dy > c)
                continue;

            if (dis[x][y] + cost[dx][dy] < dis[dx][dy]) {
                dis[dx][dy] = dis[x][y] + cost[dx][dy];
                pq.emplace(dis[dx][dy], dx, dy);
            }
        }
    }

    cout << dis[a2][b2] << "\n";
    return 0;
}

/*
2 2
1 1 2 2
4 5
6 7
= 11

4 5
2 1 4 5
3 4 222 666 1
4 5 2 1 25
19 18 20 40 9999
777 1 299 13 10
= 54
*/
