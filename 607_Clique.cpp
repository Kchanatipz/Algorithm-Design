#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, ans = -(1e9 + 7), cnt = 0;
int f[55][55], b[55];
bool chosen[55];

bool check(bool sol[], int step) {
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

void checkState(bool sol[], int step, int acc) {
    for (int i = 0; i < n; i++) cout << sol[i] << " ";
    cout << ": " << step << " & " << heuristic(step - 1) << " ";
    cout << "\n";
    return;
}

void recur(bool sol[], int step, int acc) {
    // checkState(step, acc);

    if (sol[step - 1] && acc + heuristic(step - 1) <= ans)
        return;

    cnt++;
    if (step < n) {
        sol[step] = true;
        if (check(sol, step))
            recur(sol, step + 1, acc + b[step]);
        sol[step] = false;
        recur(sol, step + 1, acc);
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

    bool sol[55];
    recur(sol, 0, 0);
    cout << ans << "\n";
    // cout << cnt << " stages\n";
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