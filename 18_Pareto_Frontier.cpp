#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
int n, ans = 0;

void recur(int start, int stop, int minY) {
    if (start == stop) {
        if (v[start].second < minY) {
            ans++;
        }
        return;
    }
    int mid = (start + stop) / 2;
    recur(start, mid, v[start].second);
    recur(mid + 1, stop, v[mid + 1].second);
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    recur(0, n, 0);
    cout << ans << "\n";
    return 0;
}