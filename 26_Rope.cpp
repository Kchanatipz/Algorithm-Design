#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int n, a, b, c;
unordered_map<int, int> m;

void update() {
    cout << "update : ";
    for (auto &[i, j] : m) {
        cout << i << " " << j << "   ";
    }
    cout << "\n";
}

int recur(int remain) {
    if (remain < 0) return -100;
    if (m.find(remain) != m.end()) {
        return m[remain];
    }
    int first = recur(remain - a);
    int second = recur(remain - b);
    int third = recur(remain - c);
    // cout << remain << " , " << remain - a << ":" << first << " ";
    // cout << remain - b << ":" << second << " " << remain - c << ":" << third << "\n";
    int ans = max(max(first, second), third);
    m[remain] = ans + 1;
    // update();
    return ans + 1;
}

int main() {
    cin >> n >> a >> b >> c;
    m[a] = m[b] = 1;
    m[c] = 1;
    cout << recur(n) << "\n";
    return 0;
}

/*
10 2 3 4
= 5
9 2 3 4
= 4
5 5 3 2
= 2
7 5 5 2
= 2
10 5 4 3
= 3
*/