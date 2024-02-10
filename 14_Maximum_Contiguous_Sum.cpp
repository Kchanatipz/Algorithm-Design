#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> sum;
int n;

int recur(int start, int stop) {
    if (start == stop) return v[start];
    int mid = (start + stop) / 2;
    int max_left = recur(start, mid);
    int max_right = recur(mid + 1, stop);
    // int diff, max_all = 0;
    // for (int i = start; i < stop; i++) {
    //     diff = sum[stop] - sum[start];
    //     if (diff > max_all) max_all = diff;
    // }
    return max(max_left, max_right);
}

int main() {
    cin >> n;
    v.resize(n);
    sum.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sum[0] = v[0];
    for (int i = 1; i < n; i++) {
        sum[i] += sum[i - 1] + v[i];
    }
    cout << recur(0, n - 1) << "\n";
}

/*
15
1 2 -1 5 3 -8 -2 4 3 -4 -5 7 -1 -2 4

8
-1 -1 -2 -2 -2 -2 -2 -2 -1
*/