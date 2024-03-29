#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, m, k, a, b, sum;
vector<vector<int>> graph;
vector<int> beauty, fire;

void dfs(int node) {
    if (beauty[node] == 0) return;
    sum -= beauty[node];
    beauty[node] = 0;
    for (int adj : graph[node]) {
        dfs(adj);
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> k;
    graph.resize(n);
    beauty.resize(n);
    fire.resize(k);
    for (int i = 0; i < n; i++) {
        cin >> beauty[i];
        sum += beauty[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> fire[i];
    }
    while (m--) {
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i : fire) {
        if (beauty[i] != 0) {
            dfs(i);
        }
        cout << sum << " ";
    }
    cout << "\n";
    return 0;
}

/*
4 3 3
10 20 30 40
2 1 0
0 1  1 2  2 3
= 30 10 0

4 3 4
5 10 15 20
1 2 3 1
0 1  1 2  1 3
= 5 5 5 5
*/