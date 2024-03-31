#include <iostream>
#include <map>
#include <vector>

using namespace std;
const int INF = 1e9 + 7;
int n, e, s, a, b, c;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void bellman_ford(int start) {
    dist[start] = 0;
    for (int round = 1; round < n; round++) {
        for (int a = 0; a < n; a++) {
            for (auto [b, w] : graph[a]) {
                dist[b] = min(dist[b], dist[a] + w);
            }
        }
    }

    bool check = true;
    for (int a = 0; a < n; a++) {
        for (auto [b, w] : graph[a]) {
            if (dist[b] > dist[a] + w) {
                check = false;
                break;
            }
        }
    }
    if (check) {
        for (int i = 0; i < n; i++)
            cout << dist[i] << " ";
    } else {
        cout << -1;
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> e >> s;
    graph.resize(n);
    dist.resize(n, INF);
    while (e--) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    bellman_ford(s);
    return 0;
}

/*
4 3 0
0 1 -1
1 2 1
2 3 4
= 0 -1 0 4

4 3 0
1 2 -1
2 3 -1
3 1 -1
= -1
*/