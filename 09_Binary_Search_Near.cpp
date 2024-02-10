#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n, m, value;

int recur(int start, int stop) {
    // cout << start << " " << stop << "\n";
    if (value < v[0]) return -1;
    if (value > v[v.size() - 1]) return v[v.size() - 1];
    if (start == stop) {
        // if ((start == 0 || start == n - 1) & v[start] <= value) return v[start];
        if (value == v[start]) return v[start];
        if (value < v[start]) return v[start - 1];
        return -1;
    }
    int mid = (start + stop) / 2;
    // cout << mid;
    if (v[mid] < value) {
        // cout << " right\n";
        return recur(mid + 1, stop);
    } else {
        // cout << " left\n";
        return recur(start, mid);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> value;
        int ans = -1;
        cout << recur(0, n - 1) << "\n";
    }
}

/*
10 20
1 5 7 9 16 20 22 25 31 35
38 34 20 30 33 12 7 27 28 16 39 39 14 12 5 21 24 33 31 0

10 3
1 5 7 9 16 20 22 25 31 35
30 33 12

4 7
14 15 20 30
10 11 14 15 16 21 68
*/