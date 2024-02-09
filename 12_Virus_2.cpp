#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;

bool recur(int start, int len) {
    if (len == 4) return abs(v[start] + v[start + 1] - v[start + 2] - v[start + 3]) <= 1;
    int diff = 0;
    len /= 2;
    for (int i = 0; i < len; i++) {
        // cout << start + i << " " << start + len + i << "\n";
        diff += v[start + i];
        diff -= v[start + len + i];
    }
    // cout << diff << "\n";
    bool ans = recur(start, len) & recur(start + len, len);
    if (abs(diff) > 1) ans = false;
    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    while (n--) {
        v.resize(pow(2, k));
        for (int i = 0; i < pow(2, k); i++) {
            cin >> v[i];
        }
        if (recur(0, pow(2, k))) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}

/*
4 3
0 0 1 1 0 0 1 1
0 0 1 1 1 0 0 0
0 1 0 1 0 1 1 1
0 1 0 1 1 1 0 0

3 4
1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0 0 1 1 1 1 1 0 1
1 1 1 0 0 1 1 1 1 0 0 1 1 0 1 1
*/