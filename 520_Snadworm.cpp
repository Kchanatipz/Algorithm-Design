#include <iostream>
#include <queue>
#include <vector>

/*
551536
*/

using namespace std;
int r, c, k, a, b, count = 0;
vector<vector<int>> d, s;
queue<pair<int, int>> q;
ิbool check = false;

void move(int ux, int uy, int x, int y) {
    int vx = ux + x;
    int vy = uy + y;
    // cout<<vx<<" : "<<vy<<"\n";
    if (vx < 0 || vy < 0 || vx >= r || vy >= c)
        return;
    if (d[vx][vy] == 1 || d[vx][vy] == 2)
        return;
    q.push({vx, vy});
    d[vx][vy] = 2;
    count++;
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> r >> c >> k;
    d.resize(r, vector<int>(c));
    s = d;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> s[i][j];
        }
    }
    while (k--) {
        cin >> a >> b;
        d[a][b] = s[a][b] = -1;
    }

    q.push({0, 0});
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();
        // cout<<ux<<" "<<uy<<":\n";

        move(ux, uy, -1, 0);
        move(ux, uy, 1, 0);
        move(ux, uy, 0, -1);
        move(ux, uy, 0, 1);
    }
    cout << count << "\n";
    return 0;
}

/*
1 dead
0 normal

2 3 0
0 0 1
1 0 0
0 0 0
0 0 0
= 4

4 3 2
0 0 0
0 0 0
0 0 0
0 0 0
0 0 1
0 1 0
1 0 0
0 0 0
1 1
= 18
*/