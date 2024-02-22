#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, ans = -1;
vector<vector<int>> v, score;
vector<int> u;

void check(vector<vector<int>> v) {
    for (auto &e : v) {
        for (auto &i : e) {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    v.resize(n + 1);
    score.resize(n + 1);
    u.resize(n + 1, -1);
    v[0] = score[0] = u;
    for (int i = 1; i <= n; i++) {
        v[i] = u;
        score[i] = u;
        for (int j = 1; j < i + 1; j++) {
            cin >> v[i][j];
        }
    }
    // check(v);
    score[1][1] = v[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i + 1; j++) {
            score[i][j] = max(score[i - 1][j - 1], score[i - 1][j]) + v[i][j];
            ans = max(ans, score[i][j]);
        }
    }
    // cout << "--------------------\n";
    // check(score);
    cout << ans << "\n";
    return 0;
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/