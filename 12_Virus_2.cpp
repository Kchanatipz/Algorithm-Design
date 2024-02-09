#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool recur() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    while (n--) {
        vector<int> v(pow(2, k));
        for (int i = 0; i < pow(2, k); i++) {
            cin >> v[i];
        }
        if (recur()) {
            cout < "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}