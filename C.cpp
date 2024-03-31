#include <iostream>
#include <random>

using namespace std;

int main() {
    // random 0-10 for 10 times
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 10);
    for (int i = 0; i < 10; i++) {
        cout << distrib(gen) << "\n";
    }
    return 0;
}