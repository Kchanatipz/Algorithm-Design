#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool recur(vector<int> v, int start, int len, bool reverse) {
    if (len == 2) {
        if (!reverse && v[start] == 0 && v[start + 1] == 1) return true;
        if (reverse && v[start] == 1 && v[start + 1] == 0) return true;
        return false;
    }
    len /= 2;
    if (!reverse) return (recur(v, start, len, false) || recur(v, start, len, true)) && recur(v, start + len, len, false);
    return (recur(v, start + len, len, false) || recur(v, start + len, len, true)) && recur(v, start, len, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    while (n--) {
        vector<int> v(pow(2, k));
        for (int i = 0; i < pow(2, k); i++) {
            cin >> v[i];
        }
        if (recur(v, 0, pow(2, k), false)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}

/*
10 3
1 0 1 0 0 1 0 1
0 1 1 0 0 1 0 1 <-
0 1 0 1 1 0 0 1
0 1 0 1 1 0 0 1
1 0 0 1 1 0 0 1
1 0 0 1 1 0 0 1
1 0 1 0 0 1 0 1
0 1 0 1 0 1 0 1
1 0 0 1 0 1 1 0 <-
1 0 0 1 1 0 0 1

5 4
0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 1 0 1 1 0 0 1
0 1 0 1 0 1 0 1 1 0 0 1 0 1 0 1
0 1 0 1 0 1 0 1 1 0 0 1 1 0 0 1
0 1 0 1 0 1 0 1 1 0 1 0 0 1 0 1
*/