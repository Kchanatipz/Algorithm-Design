// 4 Tower Defense
#include <iostream>
#include <vector>
using namespace std;

void check(vector<int> tower, vector<pair<int, int>> monster) {
    cout << "tower : ";
    for (auto &e : tower) cout << e << " ";
    cout << "\n";
    cout << "moster : ";
    for (auto &[position, health] : monster) cout << position << "," << health << " ";
    cout << endl;
}

int printSum(vector<pair<int, int>> v) {
    int sum = 0;
    for (auto &[pos, hp] : v) sum += hp;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> tower(k);
    vector<pair<int, int>> monster(m);
    for (int i = 0; i < m; i++) cin >> monster[i].first;
    for (int i = 0; i < m; i++) cin >> monster[i].second;
    for (int i = 0; i < k; i++) cin >> tower[i];
    // check(tower, monster);
    for (auto &pos : tower) {
        for (auto &[position, health] : monster) {
            if (pos - w <= position && position <= pos + w && health > 0) {
                health--;
                break;
            }
        }
    }
    // cout << "---------------------------\n";
    // check(tower, monster);
    // cout << "ANS : ";
    cout << printSum(monster) << "\n";
    return 0;
}