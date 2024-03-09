#include <iostream>
#include <vector>

using namespace std;
int l, a, b;
vector<vector<int>> v;
vector<int> u;

void check() {
    for (auto &a : v) {
        for (auto &b : a) cout << b << " ";
        cout << "\n";
    }
}

void fill(int a, int b) {
    if (v[a][b] & !v[a + 1][b] & !v[a][b + 1] & !v[a + 1][b + 1]) {
        v[a + 1][b] = v[a][b + 1] = v[a + 1][b + 1] = 1;
        cout << "ANS : 0 " << a << " " << b << "\n";
    } else if (!v[a][b] & v[a + 1][b] & !v[a][b + 1] & !v[a + 1][b + 1]) {
        v[a][b] = v[a][b + 1] = v[a + 1][b + 1] = 1;
        cout << "ANS : 1 " << a << " " << b << "\n";
    } else if (!v[a][b] & !v[a + 1][b] & v[a][b + 1] & !v[a + 1][b + 1]) {
        v[a][b] = v[a + 1][b] = v[a + 1][b + 1] = 1;
        cout << "ANS : 2 " << a << " " << b << "\n";
    } else {
        v[a][b] = v[a + 1][b] = v[a][b + 1] = 1;
        cout << "ANS : 3 " << a << " " << b << "\n";
    }
    check();
}

void recur(int x, int y, int len) {
    // cout << "@ " << x << " " << y << " " << len << "\n";
    if (len == 2) {
        cout << x << " " << y << "\n";
        fill(x, y);
        return;
    }
    len /= 2;
    recur(x, y, len);
    recur(x, y + len, len);
    recur(x + len, y, len);
    recur(x + len, y + len, len);
}

int main() {
    cin >> l >> a >> b;
    v.resize(l);
    u.resize(l);
    for (int i = 0; i < l; i++) {
        v[i] = u;
    }
    v[a][b] = 1;
    recur(0, 0, l);
    return 0;
}