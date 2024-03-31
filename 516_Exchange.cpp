#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        vector<vector<double>> table(n, vector<double>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> table[i][j];

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    table[i][j] = max(table[i][j], table[i][k] * table[k][j]);

        bool ans = false;
        for (int i = 0; i < n; i++) {
            if (table[i][i] > 1.0)
                ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}
/*
2
3
1 0.7 1.2
1.1 1 2
0.75 0.7 1
2
1 0.7
1.2 1
= y,n
*/