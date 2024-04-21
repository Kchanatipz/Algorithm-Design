#include <iostream>
#include <vector>

using namespace std;
int n, k, a, x, y;
vector<int> books;
map<int, vector<int>> sell;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;
    books.resize(n);
    for (int i = 0; i < k; i++) {
        cin >> a >> x;
        vector<int> v(a);
        for (int j = 0; j < a; j++)
    }
    return 0;
}

/*
4 3
10 3 1 2 3
30 2 1 4
20 2 3 4
= 30

78
54 3 2 7 1
52 1 6
2 3 1 4 6
100 3 2 4 7
62 2 6 1
88 2 6 3
38 1 7
26 3 3 5 7
= 82

20 11
91 4 17 19 8 14
85 4 7 9 15 2
74 9 13 16 18 3 9 10 2 4 1
40 3 2 5 6
62 9 1 16 5 8 2 20 14 10 3
14 10 10 12 14 3 19 2 9 6 11 4 83 6 6 1 10 16 2 15
99 7 4 8 15 7 17 19 10
41 5 3 8 11 12 18
18 9 18 14 13 12 19 2 5 1 6 94 9 4 14 20 5 3 2 15 10 19
= 192
*/