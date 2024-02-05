// 6 Triple Sum
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    vector<int> v;
    map<int, pair<int, int>> sum;
    bool check = true;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] != v[j]) {
                sum[v[i] + v[j]] = {v[i], v[j]};
            }
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        check = false;
        for (auto &[add, value] : sum) {
            for (auto &e : v) {
                if (add + e == x && value.first != e && value.second != e) {
                    check = true;
                    break;
                }
            }
        }
        cout << ((check) ? "YES" : "NO") << "\n";
    }
    return 0;
}

/*
4 5
-2 1 5 6
1 3 5 6 7
*/
