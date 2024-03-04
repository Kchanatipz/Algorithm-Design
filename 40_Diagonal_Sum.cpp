#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int ans = v[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                int r = i + k, c = j + k;
                if (r >= n || c >= n) break;
                sum += v[r][c];
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
4
1 2 3 4
-2 -5 2 -5
6 3 -7 1
3 -2 7 -9
= 10

2
1 2
3 4
= 5

4
-1 -1 -1 -1
-1 -1 -1 -1
-1 -1 -1 -1
-1 -1 -1 -1
= -1
*/