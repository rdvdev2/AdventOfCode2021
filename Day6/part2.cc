
#include <iostream>
#include <vector>

using namespace std;

typedef vector<long> Simulation;

const int MAX_VAL = 8;
const int RESET_VAL = 6;
const int SIMULATION_CYCLES = 256;

// pre: ---
// post: A cycle is applied to sim
void do_cycle(Simulation& sim) {
    long births = sim[0];
    for (int i = 0; i < MAX_VAL; ++i) {
        sim[i] = sim[i+1];
    }

    sim[RESET_VAL] += births;
    sim[MAX_VAL] = births;
}

int main() {
    Simulation sim(MAX_VAL+1, 0);

    int val;
    while (cin >> val) {
        ++sim[val];
        cin.ignore();
    }

    for (int i = 0; i < SIMULATION_CYCLES; ++i) {
        do_cycle(sim);
    }

    long total = 0;
    for (int i = 0; i <= MAX_VAL; ++i) {
        total += sim[i];
    }

    cout << total << endl;
}
