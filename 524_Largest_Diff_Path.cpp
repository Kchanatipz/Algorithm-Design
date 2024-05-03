#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, m, a, b, ans = 0;
vector<int> c;
vector<vector<int>> graph;
int PARENT;

void dfs(vector<bool> visited, int node, int parent) {
    visited[node] = true;
    if (parent != -1)
        ans = max(ans, c[node] - c[parent]);
    ans = max(ans, c[node] - c[PARENT]);
    for (int adj : graph[node]) {
        if (visited[adj])
            continue;
        dfs(visited, adj, node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    c.resize(n + 1);
    graph.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        vector<bool> v(n);
        PARENT = i;
        dfs(v, i, -1);
    }
    cout << ans << "\n";
    return 0;
}

/*
4 3
40 10 20 30
0 1  1 2  2 3
= 20

6 5
20 10 30 40 10 50
0 1  0 2  1 3  1 4  2 5
= 30

4 3
4 3 2 1
0 1  1 2  2 3
= 0

10 9
14 3 12 9 1 11 9 10 10 3
2 5  1 3  0 2  3 7  1 4  3 8  0 1  2 6  4 9
= 7
*/