#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, e, k, a, b, parent, ans = 0;
vector<vector<int>> graph;

int bfs(int node) {
    queue<int> q;
    vector<int> degree(n, -1);
    int count = 1;
    q.push(node);
    degree[node] = 0;
    while (!q.empty()) {
        parent = q.front();
        q.pop();
        if (degree[parent] == k)
            break;
        // cout << degree[parent] << " : " << parent << "\n";
        for (int adj : graph[parent]) {
            if (degree[adj] == -1) {
                degree[adj] = degree[parent] + 1;
                count++;
                q.push(adj);
            }
        }
    }
    return count;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> e >> k;
    graph.resize(n);
    while (e--) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int node = 0; node < n; node++) {
        // cout << node << " = \n";
        ans = max(ans, bfs(node));
        // cout << "\n";
    }
    cout << ans << "\n";
    return 0;
}

/*
7 8 2
0 6  1 6  1 5  1 4  2 3  3 4  4 5  5 6
= 6
*/