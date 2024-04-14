#include <iostream>
#include <vector>

using namespace std;

int n, m, x, ans = 1e9 + 7;
int days[1002];
vector<int> v[1001];

void recur(int start, int last, int count = 0) {
    if (count == n)
        ans = min(ans, start);
    if (start >= ans || count == n)
        return;
    for (int i = last; i < m; i++) {
        for (auto x : v[i]) {
            if (!days[x])
                count++;
            days[x]++;
        }
        recur(start + 1, i + 1, count);
        for (auto x : v[i]) {
            days[x]--;
            if (!days[x])
                count--;
        }
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        while (x--) {
            int y;
            cin >> y;
            v[i].push_back(y);
        }
    }
    recur(0, 0);
    cout << ans << "\n";
    return 0;
}
