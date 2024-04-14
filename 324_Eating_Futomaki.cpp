#include <iostream>
#include <vector>

using namespace std;

void check(vector<int> v) {
    cout << "checking\n";
    for (auto &e : v) {
        cout << e << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n), dp(n / 2);
    for (int i = 0; i < n; i++) cin >> v[i];

    int left = 0, right = n - 1;
    for (int i = 0; i < n / 2; i++) {
        cout << i << " : ";
        check(dp);
        if (v[left] > v[right]) {
            dp[i] = v[left++] + dp[i - 1];
            right--;
        } else {
            dp[i] = v[right--] + dp[i - 1];
            left--;
        }
    }
    cout << dp[(n / 2) - 1] << "\n";
    return 0;
}

/*
6
9 8 7 3 2 1
= 24

8
9 9 1 1 1 1 9 9
= 28

10
9 9 1 1 1 1 9 9 1 9
= 37
*/