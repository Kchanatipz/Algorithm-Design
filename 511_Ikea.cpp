#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, e, a, b, x;
vector<pair<int, int>> edges;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> e;
    while (e--) {
        cin >> a >> b;
        edges.push_back({a, b});
    }

    for (int i = 0; i < 5; i++) {
        vector<int> pos(n + 1);
        bool ans = true;
        for (int j = 0; j < n; j++) {
            cin >> x;
            pos[x] = j;
        }
        for (auto [a, b] : edges) {
            if (pos[a] > pos[b]) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "SUCCESS\n" : "FAIL\n");
    }
    return 0;
}

/*
4 3  1 2  2 3  3 4
1 2 3 4
1 3 4 2
1 4 2 3
4 3 2 1
3 1 2 4
= s,f,f,f,f

3 2  1 2  1 3
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
= s,s,f,f,f
*/