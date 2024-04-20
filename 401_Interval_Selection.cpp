#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, count = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].second;
    for (int i = 0; i < n; i++) cin >> v[i].first;
    sort(v.begin(), v.end());

    int last = -1;
    for (auto &[end, start] : v) {
        if (start >= last) {
            count++;
            last = end;
        }
    }
    cout << count << "\n";
    return 0;
}

/*
3
1 4 6
5 7 10
= 2

4
1 2 3 4
2 3 4 5
= 4
*/