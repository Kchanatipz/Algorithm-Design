#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m, x;
vector<vector<int>> graph;
vector<int> inDegree;

void bfs() {
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int adj : graph[u]) {
            if (--inDegree[adj] == 0)
                q.push(adj);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    graph.resize(n);
    inDegree.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> m;
        inDegree[i] = m;

        while (m--) {
            cin >> x;
            graph[x].push_back(i);
        }
    }
    bfs();
    cout << "\n";
    return 0;
}

/*
4 0 0 0 0
= 0 1 2 3

4
1 1
2 3 2
0
0
= 2/3 1 0
*/