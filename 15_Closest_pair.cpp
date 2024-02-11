#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> v;
int n;

int findDistance(int a, int b) {
    int first = v[a].first - v[b].first;
    int second = v[a].second - v[b].second;
    return sqrt(first * first + second * second);
}

int recur(int start, int stop) {
}

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    recur(0, n);
}

/*
3
1 1
2 2
5 1

6
10 2
10 4
10 6
12 3
12 5
12 7
*/