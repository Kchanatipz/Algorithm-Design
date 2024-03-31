#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> code(n);
    vector<bool> visited(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
        cin >> code[i];

    q.push(0);
    int k = 0;
    while (!q.empty() && k != 5) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        visited[node] = true;
        int next, ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int val = (code[node] ^ code[i]);
                if (val > ans) {
                    ans = val;
                    next = i;
                }
            }
            if (next != 0)
                q.push(next);
        }
        cout << next << "\n";
        k++;
    }

    long long ans = 0;
    cout << ans << "\n";
    return 0;
}

/*
4 3 10 9 6
= 37
*/