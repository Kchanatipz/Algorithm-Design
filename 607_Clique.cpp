#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, ans = -(1e9 + 7);
int f[55][55], b[55], tail[55];
bool sol[55];

bool check(int step) {
    for (int i = 0; i < step; i++)
        if (sol[i] && (!f[step][i] || !f[i][step]))
            return false;
    return true;
}

int heuristic(int step) {
    int acc = 0;
    for (int i = step; i < n; i++)
        if (f[step][i])
            acc += b[i];
    return acc;
}

void recur(int step, int acc) {
    if (sol[step - 1] && acc + heuristic(step - 1) <= ans)
        return;

    if (acc + tail[step] <= ans)
        return;

    if (step < n) {
        sol[step] = true;
        if (check(step))
            recur(step + 1, acc + b[step]);
        sol[step] = false;
        recur(step + 1, acc);
    } else {
        return void(ans = max(ans, acc));
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> f[i][j];

    tail[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--)
        tail[i] = tail[i + 1] + b[i];
    recur(0, 0);
    cout << ans << "\n";
}

/*
3  1 1 1  1 0 1 0 1 0 1 0 1
= 2

4  1 1 1 1  1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1
= 1

4  1 2 3 4  1 0 1 1 0 1 0 1 1 0 1 1 1 1 1 1
= 8
1 0 1 1
0 1 0 1
1 0 1 1
1 1 1 1

5  7 7 3 3 8  1 1 1 0 0 1 1 1 0 0 1 1 1 0 0 0 0 0 1 1 0 0 0 1 1
= 17
1 1 1 0 0
1 1 1 0 0
1 1 1 0 0
0 0 0 1 1
0 0 0 1 1
*/