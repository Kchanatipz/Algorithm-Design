#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define p pair<int, int>

using namespace std;
const int INF = 1e9 + 7;
int n, m, a, b, e, ans = 0;
vector<vector<p>> graph(505);

void dijk(int start) {
    vector<int> dist(n, INF);
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();
        cout << c << " " << u << "\n";

        for (auto [k, v] : graph[u]) {
            if (dist[u] + k < dist[v]) {
                dist[v] = dist[u] + k;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, dist[i]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> e;
        graph[a].push_back({e, b});
        graph[b].push_back({e, a});
    }

    for (int i = 0; i < n; i++) {
        cout << i << " : ";
        for (auto [x, y] : graph[i])
            cout << x << " " << y << " , ";
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
        dijk(i);
    // dijk(1);
    cout << ans << "\n";
    return 0;
}

/*
5 5
1 4 1
0 2 1
1 2 1
2 3 1
0 3 1
= 3

7 10
1 3 9
2 4 4
0 5 2
3 6 1
0 1 2
4 5 8
2 6 1
1 4 4
0 2 5
4 6 8
= 9
*/