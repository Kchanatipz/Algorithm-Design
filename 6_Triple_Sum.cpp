// 6 Triple Sum
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, target, sum, left, right;
    bool check;
    cin >> n >> m;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> target;
        check = false;
        for (int idx = 0; idx < n; idx++) {
            left = 0;
            right = n - 1;
            while (left < right) {
                sum = v[left] + v[right] + v[idx];
                if (sum == target && left != idx && right != idx) {
                    check = true;
                    break;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
            if (check) {
                break;
            }
        }
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

/*
4 5
-2 1 5 6
1 3 5 6 7
N N Y N N
*/
