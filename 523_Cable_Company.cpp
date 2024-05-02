#include <iostream>
#include <queue>
#include <vector>
#define pr pair<int, int>

using namespace std;
const int INF = 1e9 + 7;

int prim(vector<vector<pr>> graph) {
    int total = 0;
    vector<int> cost(1005, INF);
    vector<bool> taken(1005);
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    cost[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        if (taken[u])
            continue;

        taken[u] = true;
        total += c;
        for (auto [v, w] : graph[u]) {
            if (!taken[v] && cost[v] > w) {
                cost[v] = w;
                pq.push({w, v});
            }
        }
    }
    return total;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x, c;
    cin >> n;
    vector<vector<pr>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cin >> c;
            graph[i].push_back({j, c});
            graph[j].push_back({i, c});
        }
    }

    cout << prim(graph) << "\n";
    return 0;
}

/*
4
1 3 4
2 7
6
= 7

5
4 3 6 7
4 2 5
6 5
7
= 14
*/