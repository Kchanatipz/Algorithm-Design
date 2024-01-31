#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

void printPermu(vector<int> ans) {
    for (auto &e : ans) cout << e << " ";
    cout << endl;
}

void check() {
}

void recur(vector<int> &ans, int len, int idx, vector<bool> &used, map<int, int> pair, map<int, bool> &check) {
    if (idx < len) {
        for (int i = 0; i < len; i++) {
            if (!used[i] && check[i]) {
                used[i] = true;
                ans[idx] = i;
                check[pair[i]] = true;
                recur(ans, len, idx + 1, used, pair, check);
                used[i] = false;
                check[pair[i]] = false;
            }
        }
    } else {
        printPermu(ans);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<bool> u(n);
    map<int, int> m;
    map<int, bool> c;
    for (int i = 0; i < n; i++) v[i] = 8;
    if (k > 0) {
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            m[a] = b;
            c[b] = false;
        }
    } else {
        for (int i = 0; i < n; i++) {
            c[i] = true;
        }
    }
    recur(v, n, 0, u, m, c);
    return 0;
}