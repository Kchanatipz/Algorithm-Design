#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MOD = 16777216;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, ans = 0;
    bool check = false;
    cin >> x;

    queue<pair<int, int>> q;
    q.push({x, 1});

    while (!check) {
        auto [a, k] = q.front();
        q.pop();
        int b = (a + 1) % MOD;
        int c = (a * 2) % MOD;
        if (b == 0 || c == 0) {
            check = true;
            ans = k;
        }
        q.push({b, k + 1});
        q.push({c, k + 1});
    }
    cout << ans << "\n";
    return 0;
}