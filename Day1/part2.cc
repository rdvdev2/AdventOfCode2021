
#include <iostream>

using namespace std;

// input: a sequence of at least 3 naturals
// output: how many three-measurment window sums are higher than the previous one
int main() {
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    int prev_sum = a + b + c;
    a = b;
    b = c;

    int total = 0;
    while (cin >> c) {
        int sum = a + b + c;
        if (sum > prev_sum) ++total;

        a = b;
        b = c;
        prev_sum = sum;
    }
    
    cout << total << endl;
}