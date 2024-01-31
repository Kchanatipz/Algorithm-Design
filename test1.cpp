#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void process(vector<int> &ans, int k, int idx) {
    if (idx < k) ..{
            ans[idx] = 0;
            process(ans, k, idx + 1);
            ans[idx] = 1;
            process(ans, k, idx + 1);
        }
    else {
        for (int &i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    int x;
    cin >> x;
    vector<int> v(x);
    process(v, x, 0);
    return 0;
}