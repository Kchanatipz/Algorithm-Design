#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int recur(vector<vector<int>> &v, int left, int right, int top, int bottom, int n) {
    if (right - left == 1 && bottom - top == 1) return v[left][top];
    int mid = n / 2;
    for (int i = left + mid; i < right; i++) {
        for (int j = top + mid; j < bottom; j++) {
            if (v[i][j]) return 0;
        }
    }
    int p = recur(v, left, left + mid, top, top + mid, mid);
    int q = recur(v, left, left + mid, top + mid, bottom, mid);
    int r = recur(v, left + mid, right, top, top + mid, mid);
    if (!p || !q || !r) return 0;
    if (p == q || p == r) return p;
    if (q == r) return q;
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    for (int x = 0; x < 1; x++) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        cout << recur(v, 0, n, 0, n, n) << "\n";
        ;
    }
    return 0;
}

/*
4
1 1 2 2
1 0 1 0
1 2 0 0
2 0 0 0
= 2

8
1 1 2 2 3 3 2 1
1 0 1 0 1 0 1 0
1 2 0 0 1 3 0 0
2 0 0 0 3 0 0 0
2 1 2 2 0 0 0 0
2 0 2 0 0 0 0 0
2 1 0 0 0 0 0 0
2 0 0 0 0 0 0 0
= 2

2
1 2
3 0
= 2

4
1 1 1 1
1 1 1 0
1 1 0 0
1 0 0 0
= 0

2
1 1
1 0
= 1

8
1 1 2 2 3 3 2 1
1 0 1 0 1 0 1 0
1 2 0 0 1 3 0 0
2 0 0 0 3 0 0 0
2 1 2 2 0 0 0 0
2 0 2 0 0 1 0 0
2 1 0 0 0 0 0 0
2 0 0 0 0 0 0 0
= 0
*/