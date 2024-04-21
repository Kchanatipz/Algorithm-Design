#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, K[8];
vector<pair<int, int>> graph[20];
bool visited[20];

bool solve(const int &from, const int &acc, const int &target) {
    if (acc == target) return true;
    if (acc > target) return false;

    int maxcost = acc;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && !graph[i].empty())
            maxcost += graph[i][0].first;
    }
    if (maxcost < target)
        return false;

    for (auto &[cost, to] : graph[from]) {
        if (visited[to] == true) continue;

        visited[to] = true;
        bool ok = solve(to, acc + cost, target);
        visited[to] = false;

        if (ok == true) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m;
    cin >> n >> m;
    for (int i = 0; i < 8; i++)
        cin >> K[i];
    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].emplace_back(w, b);
        graph[b].emplace_back(w, a);
    }

    for (int i = 0; i < n; i++)
        sort(graph[i].rbegin(), graph[i].rend());

    for (int i = 0; i < 8; i++) {
        bool ans = false;
        for (int j = 0; j < n; j++) {
            visited[j] = true;
            ans |= solve(j, 0, K[i]);
            visited[j] = false;
            if (ans)
                break;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
/*
4 4
10 20 30 40 50 60 70 80
0 1 10
0 2 15
1 2 5
0 3 35
= y y n n y n n n
*/
