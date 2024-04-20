#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, l, cnt = 0;
    cin >> n >> l;

    vector<int> p(n);
    for (auto &x : p) cin >> x;
    sort(p.begin(), p.end());

    int cur = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (cur < p[i]) {
            cnt++;
            cur = p[i] + l - 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}

/*
6 3
2 1 3 12 7 8
= 3

5 6
2 4 9 11 14
= 2
*/