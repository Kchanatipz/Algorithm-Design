#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int f, w, n;
    cin >> f >> w >> n;
    vector<int> v(f);
    vector<bool> used(f);
    for (int i = 0; i < f; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    int cur = 0, cnt = 0;
    for (int i = 0; i < f; i++) {
        if (cur < v[i]) {
            cnt++;
            cur = v[i] + w * 2;
        }
    }
    cout << cnt << "\n";
    return 0;
}

/*
3 0 10
1 3 4
= 3

5 1 10
1 2 3 5 6
= 2

10 5 10
1 10 9 2 3 4 8 7 5 6
= 1
*/