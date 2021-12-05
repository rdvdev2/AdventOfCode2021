
#include <iostream>

using namespace std;

int main() {
    int position = 0;
    int depth = 0;

    string dir;
    while (cin >> dir) {
        int n;
        cin >> n;

        if (dir == "forward") position += n;
        else if (dir == "down") depth += n;
        else if (dir == "up") depth -= n;
    }

    cout << position * depth << endl;
    
}