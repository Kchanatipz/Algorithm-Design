#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int start = 0, end = v.size() - 1;
    while (v[start] + v[end] != k) {
        if (start == end) break;
        if (v[start] + v[end] >= k) {
            end--;
        } else {
            start++;
        }
    }
    if (start == end)
        cout << "Not found" << endl;
    else
        cout << "Ans : " << start << " " << end << endl;
    return 0;
}