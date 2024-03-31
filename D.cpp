#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int V, E, x, y, u;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int u, int step) {
    for (int i = 0; i < step; i++) cout << "  ";
    cout << "-> " << u << "\n";
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, step + 2);
        }
    }
    return;
}

void dfs_by_stack(int a) {
    stack<int> s;
    s.push(a);
    visited[a] = true;
    while (!s.empty()) {
        u = s.top();
        cout << u << "\n";
        s.pop();
        for (int b : graph[u]) {
            if (!visited[b]) {
                visited[b] = true;
                s.push(b);
            }
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

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
            dfs(i, 0);
            // dfs_by_stack(i);
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