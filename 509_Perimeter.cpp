#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, e, k, a, b;
vector<vector<int>> graph;
vector<int> dist;

void bfs() {
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int adj : graph[node]) {
            if (dist[adj] == -1 && dist[node] <= k - 1) {
                q.push(adj);
                dist[adj] = dist[node] + 1;
            }
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> e >> k;
    graph.resize(n + 1);
    dist.resize(n + 1, -1);
    while (e--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}

/*
3 4 1  0 1  1 2  1 3  0 3
= 2

5 0 1
= 0

3 4 2  0 1  1 2  2 3  1 3
= 2
*/