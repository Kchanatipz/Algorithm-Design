#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
vector<int> v, p;
int n;

int findSum(int from, int to) {
    return p[to] - p[from - 1];
}

int recur(int left, int right) {
    if (left == right) return v[left];

    int mid = (left + right) / 2;

    int left_area = recur(left, mid);
    int right_area = recur(mid + 1, right);
    int all_area = left_area;

    unordered_map<int, int> max_left;
    unordered_map<int, int> max_right;

    for (int i = mid; i >= left; i--) {
        auto it = max_left.find(v[i]);
        if (it != max_left.end())
            max_left[v[i]] = max(max_left[v[i]], findSum(i, mid));
        else
            max_left[v[i]] = findSum(i, mid);
    }

    for (int i = mid + 1; i <= right; i++) {
        auto it = max_right.find(v[i]);
        if (it != max_right.end())
            max_right[v[i]] = max(max_right[v[i]], findSum(mid + 1, i));
        else
            max_right[v[i]] = findSum(mid + 1, i);
    }

    for (auto &[i, j] : max_left) {
        auto it = max_right.find(i);
        if (it != max_right.end()) {
            all_area = max(all_area, max_left[i] + max_right[i]);
        }
    }

    // cout << left << " " << right << "\n";
    // for (auto &[i, j] : max_left) cout << i << " " << j << "    ";
    // cout << "\n";
    // for (auto &[i, j] : max_right) cout << i << " " << j << "    ";
    // cout << "\n";

    return max(max(left_area, right_area), all_area);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    v.resize(n + 1);
    p = v;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        p[i] = p[i - 1] + v[i];
    }
    cout << recur(1, n) << "\n";
    return 0;
}

/*
13
1 -2 6 3 4 -2 3 1 3 9 6 -2 3

7
1 2 -3 1 4 -3 4
*/