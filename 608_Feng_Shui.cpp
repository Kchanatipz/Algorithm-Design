#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, k, ans = -(1e9 + 7);
int c[55], p[55], tail[55];
bool chosen[55];

// using tail prefix sum
int heurestic(int step) {
    return tail[step];
}

void recur(int step, int prev, int acc) {
    if (acc + heurestic(step) <= ans)
        return;

    // check feng shui
    bool check = true;
    for (int i = 0; i < step - k + 1; i++) {
        bool check2 = true;
        for (int j = 0; j < k; j++)
            check2 &= (chosen[i + j] == p[j]);
        check &= !check2;
    }
    if (!check)
        return;

    if (step == n) {
        return void(ans = max(ans, acc));
    } else if (step < n) {
        // back tracking (not creating contiguous 1)
        if (step - 1 != prev) {
            chosen[step] = true;
            recur(step + 1, step, acc + c[step]);
        }
        chosen[step] = false;
        recur(step + 1, -1, acc);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < k; i++)
        cin >> p[i];

    tail[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; i--)
        tail[i] = tail[i + 1] + c[i];
    recur(0, -2, 0);
    cout << ans << "\n";
    return 0;
}

/*
2 2  10 20  0 1
= 10

5 3  10 11 12 13 14  1 0 1
= 25

5 3  10 20 1 1 21  0 0 1
= 32

3 3  12 18 10  0 1 0
= 22

8 5  5 12 20 16 8 20 17 11  0 1 0 0 1
= 59
*/