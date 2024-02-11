#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, max_current, max_global;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    max_global = max_current = v[0];
    for (int i = 1; i < n; i++) {
        max_current = max(v[i], v[i] + max_current);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    cout << max_global << "\n";
    return 0;
}