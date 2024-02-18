#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v, score;
vector<bool> used;
int n;

top down int recur(int step) {
    if (step < 1) return -99999;
    if (!used[step]) {
        int one = recur(step - 1);
        int two = recur(step - 2);
        int three = recur(step - 3);
        cout << step << " " << one << " " << two << " " << three << "\n";
        score[step] = max(max(one, two), three) + v[step];
        used[step] = true;
    } else {
        return score[step];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    v.resize(n + 1);
    used.resize(n + 1);
    score = v;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    score[1] = v[1];
    used[1] = true;
    recur(n);
    for (auto& e : score) cout << e << " ";
    cout << "\n";
    for (int i = 0; i <= n; i++) cout << used[i] << " ";
    cout << "\n";
    cout << score[n] << "\n";
    return 0;
}