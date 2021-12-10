
#include <iostream>
#include <vector>

using namespace std;

typedef char Fish;
typedef vector<Fish> Simulation;

const int BIRTH_RATE = 7;
const int CHILD_DAYS = 2;
const int SIMULATION_CYCLES = 80;

// pre: --
// post: A fish is added to sim
void new_fish(Simulation& sim) {
    sim.push_back(BIRTH_RATE+CHILD_DAYS-1);
}

// pre: ---
// post: A cycle of the simulation is applied
void do_cycle(Simulation& sim) {
    int fish_count = sim.size();
    
    for (int i = 0; i < fish_count; ++i) {
        --sim[i];
        if (sim[i] < 0) {
            new_fish(sim);
            sim[i] += BIRTH_RATE;
        }
    }
}

int main() {
    Simulation sim;

    int val;
    while(cin >> val) {
        sim.push_back(val);
        cin.ignore();
    }

    for (int i = 0; i < SIMULATION_CYCLES; ++i) {
        do_cycle(sim);
    }

    cout << sim.size() << endl;
}
