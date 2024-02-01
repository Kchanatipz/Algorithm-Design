#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void check(auto v) {
    for (auto &e : v) cout << e << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, x, y;
    vector<int> v;
    vector<int> index;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 0; j < y; j++) {
            v.push_back(x);
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> x;
        index.push_back(x);
    }
    // check(v);
    sort(v.begin(), v.end());
    // check(v);
    // check(index);
    for (auto &idx : index) {
        cout << v[idx - 1] << "\n";
    }
    return 0;
}
/*
5 2
1 1
10 1
5 1
1 1
3 1
5
1
*/

/*
5 3
9 1
4 5
9 3
8 3
7 7
1
15
8
*/