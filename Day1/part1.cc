
#include <iostream>

using namespace std;

// input: a sequence of naturals
// output: how many inputs were higher than the previous one
int main() {
    int prev;
    cin >> prev;

    int total = 0;
    int curr;
    while (cin >> curr) {
        if (curr > prev) ++total;
        prev = curr;
    }

    cout << total << endl;
}