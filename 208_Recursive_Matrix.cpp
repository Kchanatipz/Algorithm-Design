#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
vector<int> u;
int a, b;

void printMatrix() {
    for (auto &i : v) {
        for (auto &j : i) cout << j << " ";
        cout << "\n";
    }
}

void recur(int x, int y, int startX, int startY, int len) {
    if (x == 0) {
        v[startX][startY] = y;
        return;
    }
    len /= 2;
    recur(x - 1, y, startX, startY, len);
    recur(x - 1, y - 1, startX, startY + len, len);
    recur(x - 1, y + 1, startX + len, startY, len);
    recur(x - 1, y, startX + len, startY + len, len);
}

int main() {
    cin >> a >> b;
    v.resize(1 << a);
    u.resize(1 << a);
    for (int i = 0; i < (1 << a); i++) {
        v[i] = u;
    }
    recur(a, b, 0, 0, 1 << a);
    printMatrix();
    return 0;
}