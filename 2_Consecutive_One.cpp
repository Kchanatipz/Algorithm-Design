// 2 Consecutive One
#include <iostream>
#include <vector>
using namespace std;

void recur(vector<int> ans, int idx, int consecSize, int store, bool check) {
    if (store >= consecSize) check = true;
    if (idx < ans.size()) {
        ans[idx] = 0;
        recur(ans, idx + 1, consecSize, 0, check);
        ans[idx] = 1;
        recur(ans, idx + 1, consecSize, store + 1, check);
    } else if (check) {
        for (auto &e : ans) cout << e;
        cout << "\n";
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    recur(v, 0, k, 0, false);
}