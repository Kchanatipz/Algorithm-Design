#include <iostream>
#include <vector>

using namespace std;
int n, ans = 0;
int cols[20];
bool used[20];

bool check(int step) {
    for (int row = 0; row < step; row++) {
        if (abs(step - row) == abs(cols[step] - cols[row]))
            return false;
    }
    return true;
}

void dfs(int step) {
    if (step == n) {
        ans++;
        return;
    }
    for (int row = 0; row < n; row++) {
        if (used[row]) continue;
        used[row] = true;
        cols[step] = row;
        if (check(step))
            dfs(step + 1);
        used[row] = false;
    }
}

int main() {
    cin >> n;

    dfs(0);
    cout << ans << "\n";
    return 0;
}

/*
4 = 2
8 = 92
*/