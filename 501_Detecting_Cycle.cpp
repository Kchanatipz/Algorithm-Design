#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int parent) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs(graph, visited, adj, node);
        } else if (adj != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, V, E, x, y;
    bool ans;
    cin >> n;
    while (n--) {
        cin >> V >> E;
        vector<vector<int>> graph(V);
        while (E--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for (int i = 0; i < V; i++) {
            ans = false;
            vector<bool> visited(V);
            if (!visited[i] && dfs(graph, visited, i, -1)) {
                ans = true;
                break;
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}

/*
test
4 0
no

4 4
2 3
0 1
1 2
2 0
yes

4 3
0 1
1 2
2 0
yes

4 1
1 3
no
*/