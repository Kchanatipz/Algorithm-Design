#include <iostream>
#include <vector>

using namespace std;
vector<int> v, s;
int n;

int getSum(int a, int b) {
    return s[b] - s[a - 1];
}

int recur(int start, int stop) {
    if (start == stop) return v[start];

    int mid = (start + stop) / 2;

    int r1 = recur(start, mid);
    int r2 = recur(mid + 1, stop);

    int max_sum_left = getSum(mid, mid);
    int max_sum_right = getSum(mid + 1, mid + 1);

    // S[*][mid] --> * = l to mid
    for (int i = start; i <= mid; i++) {
        max_sum_left = max(max_sum_left, getSum(i, mid));
    }

    // S[mid+1][*] --> * = mid+1 to r
    for (int i = mid + 1; i <= stop; i++) {
        max_sum_right = max(max_sum_right, getSum(mid + 1, i));
    }
    int r3 = max_sum_left + max_sum_right;
    return max(max(r1, r2), r3);
}

int main() {
    cin >> n;
    v.resize(n + 1, 0);
    s.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] += s[i - 1] + v[i];
    }
    s[0] = 0;
    cout << recur(1, n) << "\n";
}

/*
15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4

8
-1 -1 -2 -2 -2 -2 -2 -2 -1

8
3 -4 1 2 -1 -1 5 -4
*/