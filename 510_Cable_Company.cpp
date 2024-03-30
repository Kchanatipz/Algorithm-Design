#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9 + 7;
int n, x;
vector<vector<int>> graph;
vector<int> cost;
vector<bool> taken;

void init() {
    graph.resize(n);
    cost.resize(n, INF);
    taken.resize(n);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    init();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cin >> x;
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
    }

    set<pair<int, int>> s;
    s.insert({0, 0});
    while (!s.empty()) {
        auto [c, u] = *s.begin();
        s.erase(s.begin());
        taken[u] = true;
        for (int v : graph[u]) {
            if (taken[v] == false && cost[v] >) {
                if (s.find({cost[v], v} != -1))
                    s.erase(s.find({cost[v], v}));
                cost[v] = w(u, v);
                s.insert({cost[v], v});
            }
        }
    }
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