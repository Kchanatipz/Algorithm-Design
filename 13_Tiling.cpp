#include <iostream>
#include <vector>

using namespace std;
int l, x, y;
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
        cout << "1 " << a << " " << b << "\n";
    } else if (!v[a][b] & v[a + 1][b] & !v[a][b + 1] & !v[a + 1][b + 1]) {
        v[a][b] = v[a][b + 1] = v[a + 1][b + 1] = 1;
        cout << "2 " << a << " " << b << "\n";
    } else if (!v[a][b] & !v[a + 1][b] & v[a][b + 1] & !v[a + 1][b + 1]) {
        v[a][b] = v[a + 1][b] = v[a + 1][b + 1] = 1;
        cout << "3 " << a << " " << b << "\n";
    } else {
        v[a][b] = v[a + 1][b] = v[a][b + 1] = 1;
        cout << "4 " << a << " " << b << "\n";
    }
}

void recur(int x, int y, int len) {
    cout << x << " " << y << " " << len << "\n";
    if (len == 2) {
        return;
    }
    len /= 2;
    recur();
    recur();
}

int main() {
    cin >> l >> x >> y;
    v.resize(l);
    u.resize(l);
    for (int i = 0; i < l; i++) {
        v[i] = u;
    }
    recur(0, l);
    check();
    return 0;
}