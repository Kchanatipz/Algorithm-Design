#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k, a, b;
    cin >> n >> m >> k;
    vector<vector<int>> graph(n);
    vector<int> atk(k), cost(n), dist(n, INF);
    vector<bool> visited(n);
    for (int i = 0; i < k; i++)
        cin >> atk[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    priority_queue<pair<int, int>> pq;
    for (int u : atk) {
        dist[u] = cost[u];
        pq.push({-dist[u], u});
    }
    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;

        for (int adj : graph[u]) {
            if (!visited[adj] && dist[u] + cost[adj] < dist[adj]) {
                dist[adj] = dist[u] + cost[adj];
                pq.push({-dist[adj], adj});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dist[i]);
    cout << ans << "\n";
    return 0;
}

/*
3 2 1
1
3 5 1
0 1  1 2
= 8

4 4 1
0
2 5 3 1
0 1  0 2  1 3  2 3
= 7

4 3 2
0 3
4 3 2 1
0 1  1 2  2 3
= 6
*/