
#include <iostream>

using namespace std;

int main() {
    int position = 0;
    int depth = 0;
    int aim = 0;

    string dir;
    while (cin >> dir) {
        int n;
        cin >> n;

        if (dir == "down") aim += n;
        else if (dir == "up") aim -= n;
        else if (dir == "forward") {
            position += n;
            depth += aim * n;
        }
    }

    cout << position * depth << endl;
}