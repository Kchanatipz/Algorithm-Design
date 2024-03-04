#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    a = ' ' + a, b = ' ' + b;
    int A = a.size(), B = b.size();

    vector<vector<int>> v(A, vector<int>(B));
    for (int i = 1; i < A; i++) {
        for (int j = 1; j < B; j++) {
            if (a[i] == b[j]) {
                v[i][j] = v[i - 1][j - 1] + 1;
            } else {
                v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
    }
    cout << v[A - 1][B - 1] << "\n";
    return 0;
}

/*
acbdegcedbg
begcfeubk
= 6

aaa
bbbbbbbbb
= 0

walking
alien
= 4
*/
