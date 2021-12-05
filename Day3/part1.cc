
#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 12;

int main() {
    vector<int> vec(LENGTH, 0);

    char val;
    int index = 0;
    while (cin >> val) {
        if (val == '0') --vec[index];
        else if (val == '1') ++vec[index];

        index = (index+1) % LENGTH;
    }

    int gamma = 0;
    int epsilon = 0;
    int factor = 1;
    for (int i = LENGTH - 1; i >= 0; --i) {
        if (vec[i] > 0) {
            gamma += factor;
        } else {
            epsilon += factor;
        }

        factor *= 2;
    }

    cout << gamma * epsilon << endl;
}