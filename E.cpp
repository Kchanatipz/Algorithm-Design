#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int V, E, x, y, u;
vector<vector<int>> graph;
vector<bool> visited;

void bfs_by_queue(int a) {
    queue<int> q;
    vector<int> dist(graph.size(), -1);
    q.push(a);
    dist[a] = 0;
    visited[a] = true;
    while (!q.empty()) {
        u = q.front();
        cout << dist[u] << " : " << u << "\n";
        q.pop();
        for (int b : graph[u]) {
            if (!visited[b]) {
                visited[b] = true;
                dist[b] = dist[u] + 1;
                q.push(b);
            }
        }
    }
    return;
}

int main() {
    cin >> V >> E;
    graph.resize(V);
    visited.resize(V);
    while (E--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfs_by_queue(i);
        }
    }
    return 0;
}

/*
10 8
1 8
0 1
1 4
4 5
1 2
2 3
3 6
9 7
*/