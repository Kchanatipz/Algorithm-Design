#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int V, E, x, y, ans = 0;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> degree;

void dfs(int node, vector<int> &degreeCount) {
    visited[node] = true;
    if (degree[node] > 2)
        degreeCount[2]++;
    else if (degree[node] < 2)
        degreeCount[degree[node]]++;
    for (int adj : graph[node]) {
        if (!visited[adj]) {
            dfs(adj, degreeCount);
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> V >> E;
    visited.resize(V);
    graph.resize(V);
    degree.resize(V);
    while (E--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> degreeCount(3);
            dfs(i, degreeCount);
            if ((degreeCount[0] == 1 || degreeCount[1] == 2) && degreeCount[2] == 0) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
degreeCount => 0: degree=0,  1: degree=1,  2: degree>2
*/

/*
3 2
0 1  0 2

3 2
1 0  0 2

3 0

5 4
0 1  2 3  3 4  4 2

6 2
1 2  3 4

4 6
0 1  0 2  0 3  1 2  1 3  2 3
= 1,1,3,2,4,0
*/