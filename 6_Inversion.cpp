// 6 Inversion
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}