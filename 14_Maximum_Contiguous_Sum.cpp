#include <iostream>
#include <vector>

using namespace std;
vector<int> v, s;
int n;

int recur(int start, int stop) {
    if (start == stop) return v[start];
    int mid = (start + stop) / 2;

    int r1 = recur(start, mid);
    int r2 = recur(mid + 1, stop);
    cout << "-------------\n";
    int sum, r3 = v[start];
    for (int i = 1; i < mid; i++) {
        for (int j = mid + 1; j < n; j++) {
            sum = s[j] - s[i];
            cout << i << " " << j << " " << s[j] << " " << s[i] << " " << sum << "\n";
            if (sum > r3) r3 = sum;
        }
    }
    cout << start << " " << stop << "\n";
    cout << "-- " << r1 << " " << r2 << " " << r3 << "\n";
    cout << "-------------\n";
    return max(max(r1, r2), r3);
}

int main() {
    cin >> n;
    v.resize(n + 1);
    s.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        s[i] += s[i - 1] + v[i];
    }
    s[0] = 0;
    for (auto &e : s) cout << e << " ";
    cout << recur(0, n - 1) << "\n";
}

/*
15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4

8
-1 -1 -2 -2 -2 -2 -2 -2 -1
*/