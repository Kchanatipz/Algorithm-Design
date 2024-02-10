#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
int n, m, value;

int recur(int start, int stop) {
    // cout << start << " " << stop << "\n";
    if (start == stop) {
        if (v[start] == k) return v[start];
        if (start > 0) return v[--start];
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
    return 0;
}

/*
10 8
10 13 14 14 14 15 16 16 18 200
9 10 11 14 0 200 20 16
*/