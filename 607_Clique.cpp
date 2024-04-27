#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, ans = -(1e9 + 7);
int f[55][55], b[55];
bool chosen[55];

void recur(int step, int acc) {
    if (step < n) {
        chosen[step] = false;
        recur(step + 1, acc);
        chosen[step] = true;
        recur(step + 1, acc + b[step]);
    } else {
        bool check = true;
        for (int i = 0; i < n; i++) {
            if (chosen[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (chosen[j])
                        check &= f[i][j];
                }
            }
        }
        if (check) {
            for (int i = 0; i < n; i++)
                if (i < n)
                    cout << chosen[i] << " ";
                else
                    break;
            cout << " = " << acc << "\n";
            ans = max(ans, acc);
        }
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

    cout << "---------------\n";
    recur(0, 0);
    cout << "ANS : " << ans << "\n";
}

/*
3  1 1 1
1 0 1
0 1 0
1 0 1
= 2

4  1 1 1 1
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
= 1

4  1 2 3 4
1 0 1 1
0 1 0 1
1 0 1 1
1 1 1 1
= 8

5  7 7 3 3 8
1 1 1 0 0
1 1 1 0 0
1 1 1 0 0
0 0 0 1 1
0 0 0 1 1
= 17
*/