#include <iostream>
#include <vector>

using namespace std;
int n, m, k, ans = 1e9 + 7;
vector<int> a;
int x = 0;

void recur(int step, int selected, int acc) {
    if (step > n || n - step < m - selected)
        return;
    if (abs(k - acc) > ans && acc > k)
        return;
    if (selected == m) {
        ans = min(ans, abs(acc - k));
    }

    recur(step + 1, selected + 1, acc + a[step]);
    recur(step + 1, selected, acc);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<bool> sol(n, false);
    recur(0, 0, 0);
    cout << ans << "\n";
    return 0;
}

/*
4 2 10
1 4 2 3
= 3

4 2 6
1 6 4 7
= 1
*/