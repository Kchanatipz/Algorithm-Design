// 3 Permutation with Constraint
#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b;
vector<int> ans;
vector<bool> use;
vector<int> check;

void printPermu() {
    for (auto &e : ans) cout << e << " ";
    cout << "\n";
}

void recur(int index) {
    if (index < n) {
        for (int i = 0; i < n; i++) {
            if (!used[i] && (check[i] == -1 || used[check[i]])) {
                ans[index] = i;
                used[i] = true;
                recur(index + 1);
                used[i] = false;
            }
        }
    } else {
        printPermu();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ans.resize(n);
    used.resize(n);
    check.resize(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        check[b] = a;
    }
    recur(0);
    return 0;
}