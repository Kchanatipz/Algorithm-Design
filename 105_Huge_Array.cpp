#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void check(auto v) {
    for (auto &e : v) cout << e.first << "," << e.second << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, x, y;
    vector<pair<int, int>> v;
    vector<int> index;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    for (int i = 0; i < q; i++) {
        cin >> x;
        index.push_back(x);
    }
    sort(v.begin(), v.end());
    swap(v[0].first, v[0].second);
    for (int i = 1; i < n; i++) {
        swap(v[i].first, v[i].second);
        v[i].first += v[i - 1].first;
    }
    for (auto &idx : index) {
        auto it = lower_bound(v.begin(), v.end(), make_pair(idx, 0));
        cout << it->second << "\n";
    }
    return 0;
}