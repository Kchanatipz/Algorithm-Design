#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, K, m, p, w;
    cin >> n >> K >> m;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1] - m;
    }
    while (K--) {
        cin >> p >> w;
        int ans = lower_bound(v.begin() + p, v.end(), w + v[p - 1]) - v.begin();
        cout << ans << "\n";
    }
    return 0;
}

/*
7 5 2
4 6 2 7 3 5 9
1 1     = 1
1 6     = 2
1 14    = 6
4 7     = 6
6 3     = 6
*/