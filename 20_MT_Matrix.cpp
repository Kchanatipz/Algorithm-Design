#include <iostream>

using namespace std;
int n, m, u, v, w, p;
long long x, y;

int recur(long long level, long long row, long long col) {
    if (level == 2) {
        if (row == 1 && col == 1) return u;
        if (row == 1 && col == 2) return v;
        if (row == 2 && col == 1) return w;
        return p;
    }
    long long mid = level / 2;
    if (row <= mid && col <= mid) return recur(level / 2, row, col);
    if (row <= mid && col > mid) return recur(level / 2, col - mid, row);
    if (row > mid && col <= mid) return -recur(level / 2, row - mid, col);
    return -recur(level / 2, col - mid, row - mid);
}

int main() {
    cin >> n >> m;
    cin >> u >> v >> w >> p;
    while (m--) {
        cin >> x >> y;
        cout << recur(1ll << n, x, y) << "\n";
    }
    return 0;
}

/*
3 4
1 2 3 4
1 1
2 4
4 3
4 4
*/