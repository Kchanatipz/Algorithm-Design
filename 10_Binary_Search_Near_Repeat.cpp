#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<int> v;
int n, m, value;

int recur(int start, int stop) {
    if (value < v[0]) return -1;
    if (value > v[v.size() - 1]) return v.size() - 1;
    if (start == stop) {
        if (value == v[start]) {
            while (v[start] == v[start + 1]) start++;
            return start;
        }
        return start - 1;
    }
    int mid = (start + stop) / 2;
    if (v[mid] < value) {
        return recur(mid + 1, stop);
    } else {
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
    while (m--) {
        cin >> value;
        cout << recur(0, n - 1) << "\n";
    }
}