#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool recur(vector<int> v, int start, int stop, bool reverse) {
    if (stop - start == 1) {
        return ((v[start] == 0 && v[stop] == 1) || (reverse && v[start] == 1 && v[stop] == 0));
    }
    int mid = (start + stop) / 2;
    return recur(v, start, mid, true) && recur(v, mid + 1, stop, false);
}

int main() {
    int n, k;
    cin >> n >> k;
    while (n--) {
        vector<int> v(pow(2, k));
        for (int i = 0; i < pow(2, k); i++) {
            cin >> v[i];
        }
        if (recur(v, 0, pow(2, k) - 1, false)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}

/*
4 2
1 1 0 0
1 0 0 1
0 0 0 0

3 3
1 0 0 1 0 1 0 1
1 0 1 0 1 0 0 1
1 0 1 1 1 0 0 0
*/