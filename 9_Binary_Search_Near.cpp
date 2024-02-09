#include <iostream>
#include <vector>

using namespace std;

int recur(vector<int> v, int start, int stop, int value) {
    // cout << start << " " << stop << "\n";
    if (start == stop) {
        if (value <= v[start]) return v[start];
        return -1;
    }
    int mid = (start + stop) / 2;
    // cout << mid;
    if (v[mid] < value) {
        // cout << " right\n";
        return recur(v, mid + 1, stop, value);
    } else {
        // cout << " left\n";
        return recur(v, start, mid, value);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        cout << recur(v, 0, n - 1, x) << "\n";
    }
}

/*
10 20
1 5 7 9 16 20 22 25 31 35
38 34 20 30 33 12 7 27 28 16 39 39 14 12 5 21 24 33 31 0

10 3
1 5 7 9 16 20 22 25 31 35
30 33 12
*/