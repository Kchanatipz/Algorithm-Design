#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;
int n, x, y, ans = -1;

void dfs(int node) {
    if (ans != -1)
        return;
    visited[node] = true;
    for (int adj : graph[node]) {
        if (ans != -1)
            return;
        if (!visited[adj]) {
            dist[adj] = dist[node] + 1;
            dfs(adj);
        } else if (dist[node] - dist[adj] != 1) {
            ans = dist[node] - dist[adj] + 1;
            return;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    graph.resize(n);
    visited.resize(n);
    dist.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}

/*
9
0 1
0 2
1 3
1 4
2 5
2 6
2 7
4 5
5 8
= 5
*/