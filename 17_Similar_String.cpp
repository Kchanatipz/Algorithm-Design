#include <iostream>
#include <vector>

using namespace std;
string a, b;

bool recur(int start1, int start2, int len) {
    if (len == 2) {
        return (a[start1] == b[start2] && a[start1 + 1] == b[start2 + 1]) || (a[start1 + 1] == b[start2] && a[start1] == b[start2 + 1]);
    }
    len /= 2;
    return (recur(start1, start2, len) && recur(start1 + len, start2 + len, len)) || (recur(start1 + len, start2, len) && recur(start1, start2 + len, len));
}

int main() {
    cin >> a >> b;
    if (recur(0, 0, a.size())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}