#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, k, ans = -(1e9 + 7);
int c[55], p[55];
bool chosen[55];

void recur(int step, int prev, int acc) {
    // if (acc + c[step] < ans)
    //     return;
    if (step < n) {
        if (step - 1 != prev) {
            chosen[step] = true;
            recur(step + 1, step, acc + c[step]);
        }
        chosen[step] = false;
        recur(step + 1, -1, acc);
    } else {
        bool check = true;
        cout << acc << " : ";
        for (int i = 0; i < n; i++) cout << chosen[i] << " ";
        for (int i = 0; i < n - k + 1; i++) {
            bool check2 = true;
            for (int j = 0; j < k; j++) {
                check2 &= (chosen[i + j] == p[j]);
            }
            check &= !check2;
        }
        if (check) {
            cout << " Y\n";
            ans = max(ans, acc);
        } else
            cout << " N\n";
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < k; i++) cin >> p[i];

    cout << "-------------\n";
    recur(0, -2, 0);
    cout << "ANS : " << ans << "\n";
    return 0;
}

/*
2 2
10 20
0 1
= 10

5 3
10 11 12 13 14
1 0 1
= 25

5 3
10 20 1 1 21
0 0 1
= 32

3 3
12 18 10
0 1 0
= 22

8 5
5 12 20 16 8 20 17 11
0 1 0 0 1
= 59
*/