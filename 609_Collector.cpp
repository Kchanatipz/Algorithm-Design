#include <iostream>
#include <vector>

using namespace std;
int n, k, x, ans = 1e9 + 7;
vector<vector<int>> book;
vector<int> cost, sol, collect;

void checkState(int step, int acc) {
    cout << step << " " << acc << "\nsol : ";
    for (auto &e : sol) cout << e << " ";
    cout << "\ncollect : ";
    for (auto &e : collect) cout << e << " ";
    cout << "\n\n";
}

bool check() {
    for (int i = 1; i <= n; i++) {
        if (!collect[i])
            return false;
    }
    return true;
}

bool backtrack(int step) {
    bool check = true;
    for (auto e : book[step]) {
        check &= (!collect[e]);
    }
    return check;
}

void recur(int step, int acc) {
    // checkState(step, acc);
    if (step < k) {
        sol[step] = true;
        for (auto e : book[step])
            collect[e]++;
        recur(step + 1, acc + cost[step]);
        for (auto e : book[step])
            collect[e]--;
        sol[step] = false;
        recur(step + 1, acc);
    } else if (check()) {
        // checkState(collect, step, acc);
        return void(ans = min(ans, acc));
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;
    cost.resize(k);
    book.resize(k);
    sol.resize(k);
    collect.resize(n + 1);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> cost[i] >> x;
        book[i].resize(x);
        for (int j = 0; j < x; j++)
            cin >> book[i][j];
    }

    recur(0, 0);
    cout << ans << "\n";
    return 0;
}

/*
4 3
10 3 1 2 3
30 2 1 4
20 2 3 4
= 30

7 8
54 3 2 7 1
52 1 6
2 3 1 4 6
100 3 2 4 7
62 2 6 1
88 2 6 3
38 1 7
26 3 3 5 7
= 82
*/