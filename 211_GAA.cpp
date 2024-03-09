// not done!
#include <iostream>
#include <set>
#include <vector>

using namespace std;
vector<int> v = {3, 4, 3};
set<int> s = {1};
int n, len, acc;

void check() {
    for (auto &e : v) cout << e << " ";
    cout << "\n";
}

void findLen(int max) {
    while (len < n) {
        int k = v.size();
        v.resize(v.size() * 2 + 1);
        max++;
        v[v.size() / 2] = max;
        len += max;
        for (int i = 0; i < k; i++) {
            v[v.size() - i - 1] = v[i];
            len += v[i];
        }
    }
}

char ans(int k) {
    if (s.count(k)) return 'g';
    return 'a';
}

int main() {
    cin >> n;
    len = 11;
    acc = 1;
    findLen(4);
    for (auto &e : v) {
        acc += e;
        s.insert(acc);
    }
    // for (auto &e : s) cout << e << " ";
    // cout << "\n";
    // cout << len << "\n";
    cout << ans(n) << "\n";
    return 0;
}