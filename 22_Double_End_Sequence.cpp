#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int findSum(vector<int> v, int start, int stop) {
    int sum = 0;
    for (int i = start; i <= stop; i++) {
        sum += v[i];
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> u;
    int ans = -99999;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // cout<<i<<" "<<j<<"\n";
            if (v[i] == v[j]) {
                // cout<<i<<" "<<j<<"\n";
                ans = max(ans, findSum(v, i, j));
            }
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
7
1 2 -3 1 4 -3 4

3
-3 -1 -2

10
2 -1 2 -1 2 -1 2 -1 2 -1
*/
