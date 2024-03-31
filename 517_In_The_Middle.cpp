#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, x, y;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> dist(3, vector<int>(n + 1, -1));
    vector<int> t(3);
    for (int i = 0; i < 3; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) {
        cin >> x;
        while (x--) {
            cin >> y;
            graph[i].push_back(y);
        }
    }

    for (int i = 0; i < 3; i++) {
        dist[i][t[i]] = 0;
        queue<int> q;
        q.push(t[i]);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int adj : graph[u]) {
                if (dist[i][adj] == -1) {
                    dist[i][adj] = dist[i][u] + 1;
                    q.push(adj);
                }
            }
        }
    }

    int ans = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        if (dist[0][i] != -1 && dist[1][i] != -1 && dist[2][i] != -1)
            ans = min(ans, max({dist[0][i], dist[1][i], dist[2][i]}));
    }
    cout << ans << "\n";
    return 0;
}

/*
5  1 3 5
1 2
2 1 3
2 2 4
2 3 5
1 4
= 5

10  2 5 10
2 2 4
1 3  1 1  1 5  1 6  1 7  1 8  1 9  1 4
2 8 9
= 4
*/