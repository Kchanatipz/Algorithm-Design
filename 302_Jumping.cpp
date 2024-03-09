#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v, score;
int n;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    v.resize(n);
    score.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    score[0] = v[0];
    score[1] = v[0] + v[1];
    score[2] = max(v[0] + v[2], v[0] + v[1] + v[2]);
    for (int i = 3; i < n; i++) {
        score[i] = max(max(score[i - 1], score[i - 2]), score[i - 3]) + v[i];
    }
    cout << score[n - 1] << "\n";
    return 0;
}