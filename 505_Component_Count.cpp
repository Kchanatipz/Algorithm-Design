#include <iostream>
#include <vector>

using namespace std;
int v, e, a, b;
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs(adj);
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> v >> e;
    graph.resize(v + 1);
    visited.resize(v + 1);
    while (e--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = 0;
    for (int node = 1; node <= v; node++) {
        if (!visited[node]) {
            dfs(node);
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}

/*
4 3  1 2  2 3  3 1
= 2

5 0
= 5

5 1  1 2
= 4

5 2  1 2  4 5
= 3

10 7  1 2  2 3  3 4  1 3  2 4  5 6  6 7
= 5
*/