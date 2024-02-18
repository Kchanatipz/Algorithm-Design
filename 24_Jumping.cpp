#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v, score;
vector<bool> used;
int n;

int recur(int step) {
    if (step < 1) return -99999;
    if (!used[step]) {
        // cout << step << " " << one << " " << two << " " << three << "\n";
        score[step] = max(max(recur(step - 1), recur(step - 2)), recur(step - 3)) + v[step];
        used[step] = true;
    }
    return score[step];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    v.resize(n + 1);
    used.resize(n + 1);
    score = v;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    score[1] = v[1];
    used[1] = true;
    recur(n);
    cout << score[n] << "\n";
    return 0;
}