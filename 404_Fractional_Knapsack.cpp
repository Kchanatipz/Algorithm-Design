#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    double W;
    cin >> W >> n;
    vector<double> weight(n), price(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> weight[i];

    priority_queue<tuple<double, double, double>> pq;
    double total = 0;
    for (int i = 0; i < n; i++) pq.push({price[i] / weight[i], weight[i], price[i]});
    while (!pq.empty() && W > 0) {
        auto [r, w, p] = pq.top();
        pq.pop();
        if (W > w) {
            total += p;
            W -= w;
        } else {
            total += r * W;
            W -= w;
        }
    }
    printf("%.4f\n", total);
    return 0;
}

/*
6 3
5 3 3
4 3 3
= 7.0000

5.5 4
2 3 4 5
1 2 3 4
= 8.3333
*/