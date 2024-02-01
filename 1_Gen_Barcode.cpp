// 1 Gen Barcode
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
int onesNeed, k;

void printPermu() {
    for (auto &e : ans) {
        cout << e;
    }
    cout << "\n";
}

void recur(int idx) {
    if (idx < k) {
        ans[idx] = 0;
        recur(idx + 1);
        if (onesNeed > 0) {
            ans[idx] = 1;
            onesNeed--;
            recur(idx + 1);
            onesNeed++;
        }
    } else if (onesNeed == 0) {
        printPermu();
    }
}

int main() {
    cin >> onesNeed >> k;
    ans.resize(k, 5);
    recur(0);
}
