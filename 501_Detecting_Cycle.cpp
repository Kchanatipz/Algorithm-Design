#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void check(vector<vector<int>> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << i << " : ";
        for (int j : v[i])
            cout << j << " ";
        cout << "\n";
    }
    return;
}

bool dfs(vector<vector<int>> &graph, vector<bool> &visited, int node, int parent) {
    visited[node] = true;
    cout << node << "&" << parent << " : ";
    for (int v : graph[node]) {
        cout << v;
        if (!visited[v]) {
            cout << "=1 ";
            dfs(graph, visited, v, node);
        } else if (node != parent) {
            cout << "=2 ";
            return true;
        }
        cout << "\n";
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
        vector<bool> visited(V);
        while (E--) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        check(graph);
        for (int i = 0; i < V; i++) {
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