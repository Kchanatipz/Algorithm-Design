// 1 Gen Barcode
#include <iostream>
#include <vector>
using namespace std;

void recur(vector<int> &ans, int onesNeed, int idx) {
    if (idx < ans.size()) {
        ans[idx] = 0;
        recur(ans, onesNeed, idx + 1);
        if (onesNeed > 0) {
            ans[idx] = 1;
            recur(ans, onesNeed - 1, idx + 1);
        };
    } else if (onesNeed == 0) {
        for (auto &e : ans) {
            cout << e;
        }
        cout << "\n";
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> v(b);
    recur(v, a, 0);
}
