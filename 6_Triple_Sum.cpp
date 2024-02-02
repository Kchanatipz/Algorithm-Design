// 6 Triple Sum
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<bool> used;
int n, m, x;

void check(auto v) {
    for (auto &e : v) cout << e << " ";
    cout << "\n";
}

int recur(int count, int acc) {
    cout << acc << endl;
    if (count == 3) {
        return acc;
    } else {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                recur(count + 1, acc + v[i]);
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    used.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> x;
        // cout << ((recur(0, 0) == x) ? "YES" : "NO") << "\n";
        cout << "ANS : " << recur(0, 0) << endl;
    }
    recur(0, 0);
    check(v);
    return 0;
}

/*
4 5
-2 1 5 6
1 3 5 6 7
*/