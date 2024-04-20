#include <iostream>
#include <vector>

using namespace std;
int n, ans;

void dfs(int x, int acc) {
    if (acc >= n) {
        if (acc == n)
            ans++;
        return;
    }
    for (int i = x; i <= n; i++) {
        dfs(i, acc + i);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}

/*
10 = 42
*/