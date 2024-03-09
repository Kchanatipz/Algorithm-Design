#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v(n + 1, -1000);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0) v[i] = max(v[i], v[i - a] + 1);
        if (i - b >= 0) v[i] = max(v[i], v[i - b] + 1);
        if (i - c >= 0) v[i] = max(v[i], v[i - c] + 1);
    }
    cout << v[n] << "\n";
    return 0;
}

/*
10 2 3 4
= 5
9 2 3 4
= 4
5 5 3 2
= 2
7 5 5 2
= 2
10 5 4 3
= 3
*/