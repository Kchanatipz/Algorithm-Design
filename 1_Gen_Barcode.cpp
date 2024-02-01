// 1 Gen Barcode
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int a, b;

void printPermu() {
    for (auto &e : ans) {
        cout << e;
    }
    cout << "\n";
}

void recur(int idx, int onesNeed) {
    if (idx < b) {
        ans[idx] = 0;
        recur(idx + 1, onesNeed);
        if (onesNeed > 0) {
            ans[idx] = 1;
            recur(idx + 1, onesNeed - 1);
        }
    } else if (onesNeed == 0) {
        printPermu();
    }
}

int main() {
    cin >> a >> b;
    ans.resize(b);
    recur(0, a);
}
