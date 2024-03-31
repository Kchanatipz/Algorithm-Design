#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, q, a, b, c;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n);
    map<pair<int, int>, int> cost;

    while (m--) {
        cin >> a >> b > c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cost[{a, b}] = c;
    }
    while (q--) {
        cin >> a;
    }
    return 0;
}