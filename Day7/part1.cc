
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Crabs;

Crabs read_crabs(int& min, int& max) {
    Crabs c;
    int val;
    char ignore;
    while (cin >> val) {
        c.push_back(val);
        if (min > val) min = val;
        if (max < val) max = val;
        cin >> ignore;
    }

    return c;
}

int evaluate(const Crabs& c, int pos) {
    int total = 0;
    int size = c.size();

    for (int i = 0; i < size; ++i) {
        int diff = c[i] - pos;
        if (diff > 0) total += diff;
        else total += -diff;
    }

    return total;
}

int main() {
    int min = 0, max = 0;
    Crabs c = read_crabs(min, max);

    int best = evaluate(c, min);
    for (int i = min+1; i <= max; ++i) {
        int val = evaluate(c, i);
        if (val < best) best = val;
    }

    cout << best << endl;
}